#include "Plant.h"


/**
 * @brief Construct a new Plant:: Plant object
 * 
 */
Plant::Plant() {
	info = PlantInfo();
}


/**
 * @brief Destroy the Plant:: Plant object
 * 
 */
Plant::~Plant() {
}

/**
 * @brief Construct a new Plant:: Plant object
 * 
 * @param other 
 */

Plant::Plant(const Plant& other) {
	this->info = PlantInfo(other.info);
}


/**
 * @brief sets the plant name
 * 
 * @param name 
 */
void Plant::setName(string name) {
	info.setName(name);
}

/**
 * @brief sets the plant type - Concrete Plant
 * 
 * @param type 
 */
void Plant::setType(string type) {
	info.setType(type);
}

/**
 * @brief Construct a new Plant:: Plant object
 * 
 * @param info 
 */
Plant::Plant(const PlantInfo& info):info(info) {
	// this->info = PlantInfo(info);
}

/**
 * @brief sets the water that the plant needs
 * 
 * @param water 
 */
void Plant::setWater(int water) {
	info.setWater(water,1);
}

/**
 * @brief sets the sun that the plant needs
 * 
 * @param sun 
 */
void Plant::setSun(int sun) {
	info.setSun(sun,1);
}

/**
 * @brief sets the fertiliser plant needs 
 * 
 * @param fertiliser 
 */
void Plant::setFertiliser(int fertiliser) {
	info.setFertiliser(fertiliser,1);
}


/**
 * @brief sets the attention that the plant needs
 * 
 * @param attention 
 */
void Plant::setAttention(int attention) {
	info.setAttention(attention);
}

/**
 * @brief returns the name of the plant
 * 
 * @return string 
 */
string Plant::getName() const {
	return info.getName();
}

/**
 * @brief returns the plant type
 * 
 * @return string 
 */
string Plant::getType() const {
	return info.getType();
}

/**
 * @brief returns the amount of water that the plant needs 
 * 
 * @return int 
 */
vector<int> Plant::getWater() const {
	return info.getWater();
}

/**
 * @brief return the amount of sun that the  plant needs 
 * 
 * @return int 
 */

vector<int> Plant::getSun() const {
	return info.getSun();
}


/**
 * @brief returns the amount of fertiliser that the plant needs 
 * 
 * @return int 
 */
vector<int> Plant::getFertiliser() const {
	return info.getFertiliser();
}

/**
 * @brief returns the amount of attention that the plant needs 
 * 
 * @return int 
 */
int Plant::getAttention() const {
	return info.getAttention();
}

void Plant::attach(Staff* s) {
	if (s != nullptr) {
		observers.push_back(s);
	}
}

void Plant::detach(Staff* s) {
	for (auto it = observers.begin(); it != observers.end(); ++it) {
		if (*it == s) {
			observers.erase(it);
			break;
		}
	}
}

void Plant::notify() {
	for (Staff* observer : observers) {
		if (observer != nullptr) {
			observer->handlePlant(this); 
		}
	}
}

void Plant::addPlant(Plant *p){}