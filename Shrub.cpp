/**
 * @file Shrub.cpp
 * @author Nathan Chisadza
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Shrub.h"

/**
 * @brief Construct a new Shrub:: Shrub object
 *
 */
Shrub::Shrub() : Plant() {}

/**
 * @brief Construct a new Shrub:: Shrub object
 *
 * @param info
 */
Shrub::Shrub(const PlantInfo& info) : Plant(info) {}

/**
 * @brief Construct a new Shrub:: Shrub object
 *
 * @param other
 */
Shrub::Shrub(const Plant& other) : Plant(other) {}

/**
 * @brief Destroy the Shrub:: Shrub object
 *
 */
Shrub::~Shrub() {}

/**
 * @brief stubbed
 *
 * @param p
 */
void Shrub::addPlant(Plant* p) {}

/**
 * @brief Create a copy of this Shrub.
 * @return Pointer to a new Shrub.
 */
Plant* Shrub::clone() {
  return new Shrub(*this);
}

/**
 * @brief prints the plant
 *
 */
void Shrub::print() {
  cout << left << setw(10) << info.getName() << "|";
}
