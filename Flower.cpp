#include "Flower.h"

/**
 * @brief Construct a new Flower:: Flower object
 * 
 */
Flower::Flower():Plant() {}

/**
 * @brief Construct a new Flower:: Flower object
 * 
 * @param info 
 */
Flower::Flower(PlantInfo info):Plant(info){}

/**
 * @brief Construct a new Flower:: Flower object
 * 
 * @param other 
 */
Flower::Flower(const Plant& other): Plant(other) {}

/**
 * @brief Destroy the Flower:: Flower object
 * 
 */
Flower::~Flower()  {}

Plant* Flower::clone() {
	// TODO - implement Flower::clone
	throw "Not yet implemented";
}
