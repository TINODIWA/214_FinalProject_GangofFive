/**
 * @file FlowerCreator.cpp
 * @author Unathi Tshakalisa
 * @brief File contains implementation of FlowerCreator class. Returns an instance of Flower.
 */

#include "FlowerCreator.h"

/**
 * @brief Flower Constrctor
 */
FlowerCreator::FlowerCreator() : PlantCreator() {}

/**
 * @brief Flower Destrctor
 */
FlowerCreator::~FlowerCreator() {}

/**
 * @brief Crates and returns an instance of Flower object
 * @param plantInfo Reference to PlantInfo for plant creation
 * @return instance of Flower 
 */
Plant *FlowerCreator::produce(const PlantInfo &info)
{
	return new Flower(info);
}
