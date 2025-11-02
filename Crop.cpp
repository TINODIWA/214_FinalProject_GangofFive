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
 * @brief Construct a new Crop:: Crop object
 *
 */
Crop::Crop() : Garden() {}

/**
 * @brief Destructor that deletes all plants in vector
 *
 * Iterates through the plants vector, deleting each Plant pointer
 * to prevent memory leaks
 */
Crop::~Crop() {
  for (Garden* p : plants) {
    delete p;
  }
  plants.clear();
}

/**
 * @brief Copy constructor that performs a deep copy of the Crop
 *
 * @param other The Crop object to copy from
 *
 * Creates a new Crop with its own copy of each Plant in the vector.
 * Each Plant is cloned to create a completely independent copy.
 */
Crop::Crop(const Crop& other) : Garden(other) {
  for (Garden* p : other.plants) {
    if (p != NULL) {
      plants.push_back(p->clone());
    }
  }
}

void Crop::add(Garden* p) {
  plants.push_back(p);
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

/**
 * @brief encapsulate concrete iterator with pImpl
 *
 */
struct Crop::itImpl : public Iterator {
  vector<Garden*>& plants;
  vector<Garden*>::iterator curr;

  itImpl(vector<Garden*>& p) : plants(p) { curr = p.begin(); }

  Garden* first() { return plants.front(); }

  Garden* next() {
    if (done()) return nullptr;

    return *(++curr);
  }

  bool done() { return curr == plants.end(); }

  Garden* current() { return *curr; }

  Iterator* operator++() {
    ++curr;
    return this;
  }
};

/**
 * @brief Create a Iterator object
 *
 * @return CropIterator*
 */

Iterator* Crop::createIterator() {
  return new itImpl(plants);
}

void Crop::removeDeadPlants() {
  // need to change this later to use iterator pattern

  // iterate in reverse to safely erase while iterating
  for (int i = (int)plants.size() - 1; i >= 0; --i) {
    Garden* child = plants[i];
    if (!child) continue;

    // If child is a Plant, check its state
    Plant* asPlant = dynamic_cast<Plant*>(child);
    if (asPlant) {
      string state = asPlant->getState();
      if (state.find("Dead") != string::npos) {
        // remove dead plant
        delete asPlant;
        plants.erase(plants.begin() + i);
        continue;
      }
    }

    // If child is a Crop (composite), recurse
    Crop* asCrop = dynamic_cast<Crop*>(child);
    if (asCrop) {
      asCrop->removeDeadPlants();
    }
  }
}

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
  int

  delete it;
}
