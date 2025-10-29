/**
 * @file TreeCreator.cpp
 * @author Unathi Tshakalisa
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "TreeCreator.h"

/**
 * @brief Tree Constrctor
 */
TreeCreator::TreeCreator() : PlantCreator() {}

/**
 * @brief Tree Destrctor
 */
TreeCreator::~TreeCreator() {}

/**
 * @brief Construct a new Tree Creator object
 *
 * @param other
 */
TreeCreator::TreeCreator(const PlantCreator *other) : PlantCreator(other) {}
/**
 * @brief Crates and returns an instance of Tree object
 * @param plantInfo Reference to PlantInfo for plant creation
 * @return instance of Tree
 */
Plant *TreeCreator::produce(const PlantInfo &info) {
  return new Tree(info);
}

/**
 * @brief clones the factory
 *
 * @return PlantCreator*
 */
PlantCreator *TreeCreator::clone() {
  return new TreeCreator(this);
}
