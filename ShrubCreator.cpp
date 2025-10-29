/**
 * @file ShrubCreator.cpp
 * @author Unathi Tshakalisa
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
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
 * @brief Construct a new Shrub Creator object
 *
 * @param other
 */
ShrubCreator::ShrubCreator(const PlantCreator *other) : PlantCreator(other) {}
/**
 * @brief Crates and returns an instance of Shrub object
 * @param plantInfo Reference to PlantInfo for plant creation
 * @return instance of Shrub
 */
Plant *ShrubCreator::produce(const PlantInfo &info) {
  return new Shrub(info);
}

/**
 * @brief clones the factory
 *
 * @return PlantCreator*
 */
PlantCreator *ShrubCreator::clone() {
  return new ShrubCreator(this);
}
