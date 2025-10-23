#include "Shrub.h"

/**
 * @brief Construct a new Shrub:: Shrub object
 * 
 */
Shrub::Shrub():Plant() {}

/**
 * @brief Construct a new Shrub:: Shrub object
 * 
 * @param info 
 */
Shrub::Shrub(const PlantInfo& info):Plant(info){}

/**
 * @brief Construct a new Shrub:: Shrub object
 * 
 * @param other 
 */
Shrub::Shrub(const Plant& other): Plant(other) {}

/**
 * @brief Destroy the Shrub:: Shrub object
 * 
 */
Shrub::~Shrub() {}


Plant* Shrub::clone() {
	// TODO - implement Shrub::clone
	throw "Not yet implemented";
}
