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
Plant::Plant()
    : state(new Planted()),
      waterStrategy(nullptr),
      sunStrategy(nullptr),
      fertiliserStrategy(nullptr),
      sun(0) {
  for (int i = 0; i < 2; i++) {
    water.push_back(0);
    fertiliser.push_back(0);
    sun.push_back(0);
  }
}

/**
 * @brief Destroy the Plant:: Plant object
 *
 */
Plant::~Plant() {
  if (waterStrategy) {
    delete waterStrategy;
    waterStrategy = nullptr;
  }

  if (sunStrategy) {
    delete sunStrategy;
    sunStrategy = nullptr;
  }

  if (fertiliserStrategy) {
    delete fertiliserStrategy;
    fertiliserStrategy = nullptr;
  }

  if (state) {
    delete state;
    state = nullptr;
  }
}

/**
 * @brief Construct a new Plant:: Plant object
 *
 * @param other
 */

Plant::Plant(const Plant& other) {
  name = other.name;
  type = other.type;
  water = other.water;
  sun = other.sun;
  fertiliser = other.fertiliser;
  days = other.days;
  price = other.price;
  attention = other.attention;
  state = (other.state) ? other.state->clone() : nullptr;
  waterStrategy = (other.waterStrategy) ? other.waterStrategy->clone() : nullptr;
  sunStrategy = (other.sunStrategy) ? other.sunStrategy->clone() : nullptr;
  fertiliserStrategy = (other.fertiliserStrategy) ? other.fertiliserStrategy->clone() : nullptr;
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
  this->water[1] = water;
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
void Plant::setWaterCare(char level) {
  delete waterStrategy;
  this->waterStrategy = setCareStrategy(level);
}

/**
 * @brief sets the sun strategy of the plant
 *
 * @param sun
 */
void Plant::setSunCare(char level) {
  delete sunStrategy;
  this->sunStrategy = setCareStrategy(level);
}

/**
 * @brief sets the fertiliser strategy of the plant
 *
 * @param fertiliser
 */
void Plant::setFertiliserCare(char level) {
  delete fertiliserStrategy;
  this->fertiliserStrategy = setCareStrategy(level);
}

/**
 * @brief Returns instannce of required PlantCare level
 *
 * @param level
 */
PlantCare* Plant::setCareStrategy(char level) {
  switch (level) {
    case 'H':
      return new High();
      break;

    case 'M':
      return new Medium();
      break;

    case 'L':
      // cout << "LOW set...great!!." << endl;
      return new Low();
      break;

    default:
      cout << "No care strategy set...try again." << endl;
      return NULL;
      break;
  }
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
void Plant::setPrice(float price) {
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
 * @return float
 */
float Plant::getPrice() const {
  return price;
}

/**
 * @brief Attach an observer (Staff) to this Plant
 * Adds a Staff member to the list of observers that will be notified of state changes
 * 
 * @param s Pointer to Staff object to attach as observer
 */
void Plant::attach(Staff* s) {
  if (s != nullptr) {
    staff.push_back(s);
  }
}

/**
 * @brief Detach an observer (Staff) from this Plant
 * Removes a Staff member from the list of observers
 * Uses operator== to find matching Staff member
 * 
 * @param s Pointer to Staff object to detach
 */
void Plant::detach(Staff* s) {
  if (s == nullptr) 
    return;
  for (auto it = staff.begin(); it != staff.end(); ++it) {
    if (*it != nullptr && **it == *s) {
      staff.erase(it);
      break;
    }
  }
}

/**
 * @brief Notify all attached observers of a state change
 * Calls update() on each Staff observer in the list
 * Part of the Observer design pattern implementation
 */
void Plant::notify() {
  for (Staff* observer : staff) {
    if (observer != nullptr) {
      observer->update(this);
    }
  }
}

/**
 * @brief updates daily water level
 */
void Plant::updateWaterLevel(int newLevel) {
  this->water[0] = newLevel;
}

/**
 * @brief Decreases the current plantlevels based on Sun Strategy
 * @param decrease attribute determined by Sun Strategy
 */
void Plant::updateSunLevel(int newLevel) {
  if (sun.size() >= 1) sun[0] = newLevel;
}

void Plant::transpire(int decreasedLevel) {
  this->water[0] = sunStrategy->apply(water[0],sun,-1);
  this->fertiliser[0] = sunStrategy->apply(fertiliser[0],sun,-1);
  state->handleChange();
}

/**
 * @brief Decreases the current  water level based on Sun Strategy
 * @param newLevel attribute determined by Sun Strategy
 */
void Plant::updateFertiliserLevel(int newLevel) {
  this->fertiliser[0] = newLevel;
}

/**
 * @brief Updates current day in the life cycle and resets daily water Level
 */
void Plant::updateDay() {
  this->days[0]++;
  updateFertiliserLevel(0);
  updateWaterLevel(0);
}

/**
 * @brief Returns plants current state
 */
string Plant::getState() {
  return state->getState();
}

/**
 * @brief Returns clone of the plant
 */
Garden* Plant::clone() {
  return new Plant(*this);
}

/**
 * @brief prints the plant
 *
 */
string Plant::print() {
  stringstream ss;
  ss << left << setw(10) << this->name << "|";
  return ss.str();
}

/**
 * @brief advice on how to care for the plant
 *
 * @return string
 */
string Plant::advice() {
  stringstream ss;

  ss << "Advice on how to care for your " << name << "\n";

  ss << "Water:\t" << water[1] << " ml/day\n";
  ss << "Fertiliser:\t" << fertiliser[1] << "ml/day\n";

  // not sure abt sun and attention yet

  return ss.str();
}

/**
 * @brief return if two plants are equal based on name
 *
 */
bool Plant::operator==(string name) {
  if (this->name == name) {
    return true;
  }
  return false;
}
