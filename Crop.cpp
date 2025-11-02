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

void Crop::print() {
  vector<Garden*>::iterator it = plants.begin();
  //cout<<"ERROR\n";

  int width = 40;
  for (int i = 0; i < width; i++) cout << "-";

  cout << endl;
  int i = 1;
  while (it != plants.end()) {
    (*it)->print();
    ++it;

    if (i % 4 == 0) {
      cout << endl;
      for (int i = 0; i < width; i++) cout << "-";
      cout << endl;
    }

    ++i;
  }

  cout << "\n===================================\n";
}
