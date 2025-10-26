/**
 * @file ShrubCreator.cpp
 * @author Unathi Tshakalisa
 * @brief File contains implementation of ShrubCreator class. Returns an instance of Shrub.
 */

#include "ShrubCreator.h"

/**
 * @brief Shrub Constrctor
 */
ShrubCreator::ShrubCreator() : PlantCreator() {}

/**
 * @brief Shrub Destrctor
 */
ShrubCreator::~ShrubCreator() {}

/**
 * @brief Crates and returns an instance of Shrub object
 * @param plantInfo Reference to PlantInfo for plant creation
 * @return instance of Shrub 
 */
Plant *ShrubCreator::produce(const PlantInfo &info)
{
	// TODO - implement ShrubCreator::produce
	return new Shrub(info);
}
