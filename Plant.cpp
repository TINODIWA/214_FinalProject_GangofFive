/**
 * @file Plant.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Plant.h"

/**
 * @brief Construct a new Plant:: Plant object
 *
 */
Plant::Plant() {}

/**
 * @brief Destroy the Plant:: Plant object
 *
 */
Plant::~Plant() {}

/**
 * @brief Construct a new Plant:: Plant object
 *
 * @param other
 */

Plant::Plant(const Plant* other) {
  if (!other) return;

  name = other->name;
  type = other->type;
  water = other->water;
  sun = other->sun;
  fertiliser = other->fertiliser;
  days = other->days;
  price = other->price;
  attention = other->attention;
  state = (other->state) ? other->state->clone() : nullptr;

  if (other->staff.size() > 0) {
    vector<Staff*>::const_iterator it = other->staff.begin();
    while (it != other->staff.end()) {
      staff.push_back(*it);  // shallow copy coz staff have multiple plants
    }
  }

  // STRATEGY COPYING WILL BE ADDED WHEN THE CLASSES ARE ADDED
}

/**
 * @brief sets the plant name
 *
 * @param name
 */
void Plant::setName(string name) {
  this->name = name;
}

/**
 * @brief sets the plant type - Concrete Plant
 *
 * @param type
 */
void Plant::setType(string type) {
  this->type = type;
}

/**
 * @brief sets the water that the plant needs
 *
 * @param water
 */
void Plant::setWater(int water) {
  this->water[1] = water;  // seting
}

/**
 * @brief sets the sun that the plant needs
 *
 * @param sun
 */
void Plant::setSun(int sun) {
  this->sun[1] = sun;
}

/**
 * @brief sets the fertiliser plant needs
 *
 * @param fertiliser
 */
void Plant::setFertiliser(int fertiliser) {
  this->fertiliser[1] = fertiliser;
}

/**
 * @brief sets the attention that the plant needs
 *
 * @param attention
 */
void Plant::setAttention(int attention) {
  this->attention = attention;
}

/**
 * @brief sets the water strategy of the plant
 *
 * @param water
 */
void Plant::setWaterCare(PlantCare* water) {
  // water.clone();
}

/**
 * @brief sets the sun strategy of the plant
 *
 * @param sun
 */
void Plant::setSunCare(PlantCare* sun) {
  // sun.clone()
}

/**
 * @brief sets the fertiliser strategy of the plant
 *
 * @param fertiliser
 */
void Plant::setFertiliserCare(PlantCare* fertiliser) {
  // fertiliser.clone()
}

/**
 * @brief sets the days for the life cycle
 *
 * @param days
 */
void Plant::setDays(vector<int> days) {
  this->days = days;
}

/**
 * @brief sets the price of the plant
 *
 * @param price
 */
void Plant::setPrice(int price) {
  this->price = price;
}

/**
 * @brief returns the name of the plant
 *
 * @return string
 */
string Plant::getName() const {
  return name;
}

/**
 * @brief returns the plant type
 *
 * @return string
 */
string Plant::getType() const {
  return type;
}

/**
 * @brief returns the amount of water that the plant needs
 *
 * @return int
 */
vector<int> Plant::getWater() const {
  return water;
}

/**
 * @brief return the amount of sun that the  plant needs
 *
 * @return int
 */

vector<int> Plant::getSun() const {
  return sun;
}

/**
 * @brief returns the amount of fertiliser that the plant needs
 *
 * @return int
 */
vector<int> Plant::getFertiliser() const {
  return fertiliser;
}

/**
 * @brief returns the amount of attention that the plant needs
 *
 * @return int
 */
int Plant::getAttention() const {
  return attention;
}

/**
 * @brief returns the water care strategy
 *
 * @return PlantCare*
 */
PlantCare* Plant::getWaterCare() const {
  return waterStrategy;
}

/**
 * @brief returns the sun care strategy
 *
 * @return PlantCare*
 */
PlantCare* Plant::getSunCare() const {
  return sunStrategy;
}

/**
 * @brief return the fertiliser care strategy
 *
 * @return PlantCare*
 */
PlantCare* Plant::getFertiliserCare() const {
  return fertiliserStrategy;
}

/**
 * @brief returns the days of lifecycle progression of the plant
 *
 * @return vector<int>
 */
vector<int> Plant::getDays() const {
  return days;
}

/**
 * @brief returns the price of the plant
 *
 * @return int
 */
int Plant::getPrice() const {
  return price;
}

void Plant::attach(Staff* s) {
  // TODO(user) - implement Plant::attach
  // throw "Not yet implemented";
}

void Plant::detach(Staff* s) {
  // TODO(user) - implement Plant::detach
  // throw "Not yet implemented";
}

void Plant::notify() {
  // TODO(user) - implement Plant::notify
  // throw "Not yet implemented";
}

/**
 * @brief clones the plant
 *
 * @return Garden*
 */
Garden* Plant::clone() {
  return new Plant(this);
}

/**
 * @brief prints the plant
 *
 */
void Plant::print() {
  cout << left << setw(10) << this->name << "|";
}
