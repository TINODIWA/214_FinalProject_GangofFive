/**
 * @file FlowerCreator.cpp
 * @author Unathi Tshakalisa
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
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

FlowerCreator::FlowerCreator(const PlantCreator* other) : PlantCreator(other) {}
/**
 * @brief Crates and returns an instance of Flower object
 * @param plantInfo Reference to PlantInfo for plant creation
 * @return instance of Flower
 */
Plant* FlowerCreator::produce(const PlantInfo& info) {
    return new Flower(info);
}

/**
 * @brief clones the factory
 *
 * @return FlowerCreator::PlantCreator*
 */
PlantCreator* FlowerCreator::clone() {
    return new FlowerCreator(this);
}
