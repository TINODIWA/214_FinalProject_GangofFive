/**
 * @file PlantCreator.cpp
 * @author Unathi Tshakalisa
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "PlantCreator.h"

PlantCreator::PlantCreator() {}
/**
 * @brief Construct a new Plant Creator:: Plant Creator object
 *
 * @param other
 */
PlantCreator::PlantCreator(const PlantCreator* other) {}

/**
 * @brief Destroy the Plant Creator:: Plant Creator object
 *
 */
PlantCreator::~PlantCreator() {}

/**
 * @brief Create function that delegate plant creation
 * @param plantInfo Reference to PlantInfo for plant creation
 */
Plant* PlantCreator::create(const PlantInfo& plantInfo) {
  return produce(plantInfo);
}
