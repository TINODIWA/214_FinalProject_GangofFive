/**
 * @file PlantBuilder.cpp
 * @author Swelihle Makhathini
 * @brief
 * @version 0.1
 * @date 2025-10-30
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "PlantBuilder.h"

/**
 * @brief Construct a new Plant Builder:: Plant Builder object
 *
 */
PlantBuilder::PlantBuilder() : Builder(),p(nullptr) {}

/**
 * @brief Destroy the Plant Builder:: Plant Builder object
 *
 */
PlantBuilder::~PlantBuilder() {
  if (p) {
    delete p;
    p = nullptr;
  }
}

/**
 * @brief Construct a new Plant Builder:: Plant Builder object
 *
 * @param other
 */
PlantBuilder::PlantBuilder(const PlantBuilder* other) {
  this->p = new Plant(*other->p);
}

/**
 * @brief sets the name attribute
 *
 * @param name
 * @return Builder*
 */
Builder* PlantBuilder::setName(string name) {
  p->setName(name);
  return this;
}

/**
 * @brief sets the type attribute
 *
 * @param type
 * @return Builder*
 */
Builder* PlantBuilder::setType(string type) {
  p->setType(type);
  return this;
}

/**
 * @brief sets the required water
 *
 * @param water
 * @return Builder*
 */
Builder* PlantBuilder::setWater(int water) {
  p->setWater(water);
  return this;
}

/**
 * @brief sets the required sun
 *
 * @param sun
 * @return Builder*
 */
Builder* PlantBuilder::setSun(int sun) {
  p->setSun(sun);
  return this;
}

/**
 * @brief sets the required fertiliser
 *
 * @param fertiliser
 * @return Builder*
 */
Builder* PlantBuilder::setFertiliser(int fertiliser) {
  p->setFertiliser(fertiliser);
  return this;
}

/**
 * @brief sets the attention attribute
 *
 * @param attention
 * @return Builder*
 */
Builder* PlantBuilder::setAttention(int attention) {
  p->setAttention(attention);
  return this;
}

/**
 * @brief sets the water care
 *
 * @param water
 * @return Builder*
 */
Builder* PlantBuilder::setWaterCare(PlantCare* water) {
  return this;
}

/**
 * @brief sets the sun care
 *
 * @param sun
 * @return Builder*
 */
Builder* PlantBuilder::setSunCare(PlantCare* sun) {
  return this;
}

/**
 * @brief sets the fertiliser care
 *
 * @param fertiliser
 * @return Builder*
 */
Builder* PlantBuilder::setFertiliserCare(PlantCare* fertiliser) {
  return this;
}

/**
 * @brief sets the days of the plants lifecycle progression
 * 
 * @param days 
 * @return Builder* 
 */
Builder* PlantBuilder::setDays(vector<int> days) {
    p->setDays(days);
    return this;
}

/**
 * @brief sets the price of the plant
 * 
 * @param price 
 * @return Builder* 
 */
Builder* PlantBuilder::setPrice(int price) {
    p->setPrice(price);
    return this;
}

/**
 * @brief returns the constructed plant
 *
 * @return Plant*
 */
Plant* PlantBuilder::build() {
  return p;
}



/**
 * @brief clones the builder
 *
 * @return Builder*
 */
PlantBuilder* PlantBuilder::clone() {
  return new PlantBuilder(*this);
}

/**
 * @brief resets the builder to make a new plant
 *
 */
void PlantBuilder::reset() {
  p = nullptr;
}
