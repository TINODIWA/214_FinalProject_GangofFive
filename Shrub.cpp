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

/**
 * @brief stubbed 
 * 
 * @param p 
 */
void Shrub::addPlant(const PlantInfo& p){}

/**
 * @brief Returns a clone of current plant 
 * @return Plant pointer
 */
Plant* Shrub::clone() {
	// TODO - implement Shrub::clone
	throw "Not yet implemented";
}
