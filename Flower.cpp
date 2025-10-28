/**
 * @file Flower.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Flower.h"

/**
 * @brief Construct a new Flower:: Flower object
 *
 */
Flower::Flower() : Plant() {}

/**
 * @brief Construct a new Flower:: Flower object
 *
 * @param info
 */
Flower::Flower(const PlantInfo &info) : Plant(info) {}

/**
 * @brief Construct a new Flower:: Flower object
 *
 * @param other
 */
Flower::Flower(const Plant &other) : Plant(other) {}

/**
 * @brief Destroy the Flower:: Flower object
 *
 */
Flower::~Flower() {}

/**
 * @brief stubbed
 *
 * @param p
 */
void Flower::addPlant(Plant *p) {}

Plant *Flower::clone() {
    return new Flower(*this);
}

/**
 * @brief prints the plant
 *
 */
void Flower::print() {
    cout << left << setw(10) << info.getName() << "|";
}