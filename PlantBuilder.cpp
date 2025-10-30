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
PlantBuilder::PlantBuilder() :p(nullptr) {}

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
PlantBuilder* PlantBuilder::setName(string name) {
  p->setName(name);
  return this;
}

/**
 * @brief sets the type attribute
 *
 * @param type
 * @return Builder*
 */
PlantBuilder* PlantBuilder::setType(string type) {
  p->setType(type);
  return this;
}

/**
 * @brief sets the required water
 *
 * @param water
 * @return Builder*
 */
PlantBuilder* PlantBuilder::setWater(int water) {
  p->setWater(water);
  return this;
}

/**
 * @brief sets the required sun
 *
 * @param sun
 * @return Builder*
 */
PlantBuilder* PlantBuilder::setSun(int sun) {
  p->setSun(sun);
  return this;
}

/**
 * @brief sets the required fertiliser
 *
 * @param fertiliser
 * @return Builder*
 */
PlantBuilder* PlantBuilder::setFertiliser(int fertiliser) {
  p->setFertiliser(fertiliser);
  return this;
}

/**
 * @brief sets the attention attribute
 *
 * @param attention
 * @return Builder*
 */
PlantBuilder* PlantBuilder::setAttention(int attention) {
  p->setAttention(attention);
  return this;
}

/**
 * @brief sets the water care
 *
 * @param water
 * @return Builder*
 */
PlantBuilder* PlantBuilder::setWaterCare(PlantCare* water) {
  return this;
}

/**
 * @brief sets the sun care
 *
 * @param sun
 * @return Builder*
 */
PlantBuilder* PlantBuilder::setSunCare(PlantCare* sun) {
  return this;
}

/**
 * @brief sets the fertiliser care
 *
 * @param fertiliser
 * @return Builder*
 */
PlantBuilder* PlantBuilder::setFertiliserCare(PlantCare* fertiliser) {
  return this;
}

/**
 * @brief sets the days of the plants lifecycle progression
 * 
 * @param days 
 * @return Builder* 
 */
PlantBuilder* PlantBuilder::setDays(vector<int> days) {
    p->setDays(days);
    return this;
}

/**
 * @brief sets the price of the plant
 * 
 * @param price 
 * @return Builder* 
 */
PlantBuilder* PlantBuilder::setPrice(int price) {
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
  p = new Plant();
}
