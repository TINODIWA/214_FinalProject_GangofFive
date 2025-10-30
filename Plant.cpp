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
 * @brief Construct a new Plant object
 *
 * @param name
 * @param type
 * @param water
 * @param sun
 * @param fertiliser
 * @param strategy
 * @param state
 * @param staff
 * @param days
 * @param price
 */
Plant::Plant(string name, string type, vector<int> water, vector<int> sun, vector<int> fertiliser,
             PlantCare* waterStrategy, PlantCare* sunStrategy, PlantCare* fertiliserStrategy, vector<int> days,
             int price, int attention)
    : name(name),
      type(type),
      price(price),
      water(water),
      sun(sun),
      fertiliser(fertiliser),
      days(days),
      attention(attention) {
  this->state = new Planted();
  // PLEASE ADD INITIALISATION WHEN PLANTCARE SUBCLASSES ARE MADE
}

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

Plant::Plant(const Plant& other)
    : name(other.name),
      type(other.type),
      water(other.water),
      sun(other.sun),
      fertiliser(other.fertiliser),
      days(other.days),
      price(other.price),
      attention(attention) {
  state = (other.state) ? other.state->clone() : nullptr;

  if (other.staff.size() > 0) {
    vector<Staff*>::const_iterator it = other.staff.begin();
    while (it != other.staff.end()) {
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
  //water.clone();
}

/**
 * @brief sets the sun strategy of the plant
 * 
 * @param sun
 */
void Plant::setSunCare(PlantCare* sun) {
  //sun.clone()
}

/**
 * @brief sets the fertiliser strategy of the plant
 * 
 * @param fertiliser 
 */
void Plant::setFertiliserCare(PlantCare* fertiliser) {
  //fertiliser.clone()
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
 * @brief stubbed - for adding plans to a crop
 *
 * @param p
 */
void Plant::addPlant(Plant* p) {}
