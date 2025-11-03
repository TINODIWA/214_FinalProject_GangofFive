/**
 * @file Crop.cpp
 * @author Nathan Chisadza, Swelihle Makhathini
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Crop.h"

/**
 * @brief encapsulate concrete iterator with pImpl
 *
 */
class Crop::itImpl {
 private:
  vector<Garden*> plants;

 public:

 /**
  * @brief Construct a new it Impl object
  * 
  */
  itImpl(){}

  /**
   * @brief Construct a new it Impl object
   * 
   * @param other 
   */
  itImpl(const itImpl& other) {
    for (Garden* p : other.plants) {
      if (p) plants.push_back(p->clone());
    }
  }

  /**
   * @brief Destroy the it Impl object
   * 
   */
  ~itImpl(){
    for(Garden* p: plants){
      if(p){
        delete p;
        p = nullptr;
      }
    }

    plants.clear();
  }
  /**
   * @brief adds a plant to the plants vector
   *
   * @param p
   */
  void add(Garden* p) {
    if (p) {
      plants.push_back(p);
    }
  }

  /**
   * @brief Create a Iterator object
   *
   * @return Iterator*
   */
  Iterator* createIterator() { return new IteratorImpl(plants); };

  /**
   * @brief the implementation for the iterator
   *
   */
  class IteratorImpl : public Iterator {
    vector<Garden*>& plants;
    vector<Garden*>::iterator curr;

   public:
    /**
     * @brief Construct a new Iterator Impl object
     *
     * @param p
     */
    IteratorImpl(vector<Garden*>& p) : plants(p) { curr = p.begin(); }

    /**
     * @brief returns the first element and resets the current index to the beginning
     *
     * @return Garden*
     */
    Garden* first() {
      curr = plants.begin();
      return current();
    }

    /**
     * @brief returns the next object and updates current
     *
     * @return Garden*
     */
    Garden* next() {
      if (done()) return nullptr;

      return *(++curr);
    }

    /**
     * @brief has the end of the vector been reached
     *
     * @return true
     * @return false
     */
    bool done() { return curr == plants.end(); }

    /**
     * @brief returns the current element being pointed to
     *
     * @return Garden*
     */
    Garden* current() { return *curr; }

    /**
     * @brief increments the iterator
     *
     * @return Iterator*
     */
    Iterator* operator++() {
      ++curr;
      return this;
    }

    /**
     * @brief removes the current element being pointed
     *
     * @return Garden*
     */
    Garden* remove() {
      if (!plants.empty() && curr != plants.end()) {
        Garden* rem = (*curr);
        curr = plants.erase(curr);

        return rem;
      }
      return nullptr;
    }
  };
};

/**
 * @brief Construct a new Crop:: Crop object
 *
 */
Crop::Crop() : Garden(), pImpl(new itImpl()) {}
/**
 * @brief Destructor that deletes all plants in vector
 *
 * Iterates through the plants vector, deleting each Plant pointer
 * to prevent memory leaks
 */
Crop::~Crop() {
 if(pImpl){
  delete pImpl;
  pImpl = nullptr;
 }
}

/**
 * @brief Copy constructor that performs a deep copy of the Crop
 *
 * @param other The Crop object to copy from
 *
 * Creates a new Crop with its own copy of each Plant in the vector.
 * Each Plant is cloned to create a completely independent copy.
 */
Crop::Crop(const Crop& other) : Garden(other), pImpl(new itImpl(*other.pImpl)) {}

void Crop::add(Garden* p) {
  pImpl->add(p);
}

Iterator* Crop::createIterator() {
  return pImpl->createIterator();
}
/**
 * @brief Create a copy of this Crop.
 * @return Pointer to a new Crop.
 */
Garden* Crop::clone() {
  return new Crop(*this);
}

/**
 * @brief prints out all the plants in a crop
 *
 */
string Crop::print() {
  Iterator* it = createIterator();
  stringstream crop;

  int width = 40;
  for (int i = 0; i < width; i++) crop << "-";

  crop << "\n";
  int i = 1;
  while (!it->done()) {
    crop << (**it)->print();
    ++(*it);

    if (i % 4 == 0) {
      crop << "\n";
      for (int i = 0; i < width; i++) crop << "-";
      crop << "\n";
    }

    ++i;
  }

  crop << "\n===================================\n";

  delete it;

  return crop.str();
}

// void Crop::removeDeadPlants() {
// need to change this later to use iterator pattern

// iterate in reverse to safely erase while iterating
// for (int i = (int)plants.size() - 1; i >= 0; --i) {
//   Garden* child = plants[i];
//   if (!child) continue;

//   // If child is a Plant, check its state
//   Plant* asPlant = dynamic_cast<Plant*>(child);
//   if (asPlant) {
//     string state = asPlant->getState();
//     if (state.find("Dead") != string::npos) {
//       // remove dead plant
//       delete asPlant;
//       plants.erase(plants.begin() + i);
//       continue;
//     }
//   }

//   // If child is a Crop (composite), recurse
//   Crop* asCrop = dynamic_cast<Crop*>(child);
//   if (asCrop) {
//     asCrop->removeDeadPlants();
//   }
// }
//}

/**
 * @brief summary of the number of plants and what plant
 *
 * @return string
 */
map<string, int> Crop::summary(map<string, int>& sum) {
  Iterator* it = createIterator();
  int PlantCount = 0;
  string type = "";

  while (!it->done()) {
    map<string, int> plant = (**it)->summary(sum);

    if (plant.empty()) {
      type = (type == "") ? (**it)->print() : type;
      ++PlantCount;
    } else {
      if (type != "") sum[type] = PlantCount;
    }

    ++(*it);
  }
  delete it;

  if (type != "") sum[type] = PlantCount;
  return sum;
}

/**
 * @brief return the specified number of plants with the passed in name;
 *
 * @param name
 * @param num
 * @return Garden*
 */
vector<Garden*> Crop::get(string name, int num) {
  Iterator* it = createIterator();
  vector<Garden*> g;
  int count = num;

  while (!it->done() && count > 0) {
    if ((**it)->operator==(name)) {
      g.push_back(it->remove());
      --count;
    } else {
      vector<Garden*> curr = (**it)->get(name, count);

      if (!curr.empty()) {
        for (Garden* c : curr) {
          g.push_back(c);
        }
        count -= curr.size();
      }

      ++(*it);
    }
  }

  delete it;
  return g;
}

/**
 * @brief return the pointer to the first plant with the passed in name
 *
 * @param name
 * @return Garden*
 */
Garden* Crop::get(string name) {
  Iterator* it = createIterator();
  Garden* want = nullptr;

  while (!it->done()) {
    if ((**it)->operator==(name)) {
      want = *(*it);
      break;
    } else {
      want = (**it)->get(name);
    }

    if (want) {
      delete it;
      return want;
    }

    ++(*it);
  }

  delete it;
  return want;
}
