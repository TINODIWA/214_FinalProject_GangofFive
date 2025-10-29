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
Flower::Flower(const PlantInfo &info) : Plant(info){}

/**
 * @brief Construct a new Flower:: Flower object
 * 
 * @param other 
 */
Flower::Flower(const Plant& other) : Plant(other) {}

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
void Flower::addPlant(const PlantInfo& p) {}

/**
 * @brief Create a copy of this Flower.
 * @return Pointer to a new Flower.
 */
Plant* Flower::clone() {
	return new Flower(*this);
}
