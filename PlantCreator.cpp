/**
 * @file PlantCreator.cpp
 * @author Unathi Tshakalisa
 * @brief File contains implementation of Plantcreator class. Used to delegate plant creation.
 */

#include "PlantCreator.h"

/**
 * @brief Create function that delegate plant creation
 * @param plantInfo Reference to PlantInfo for plant creation
 */
Plant* PlantCreator::create(const PlantInfo& plantInfo) {
	return produce(plantInfo);
}
