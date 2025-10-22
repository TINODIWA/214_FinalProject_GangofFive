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
Plant::Plant(PlantInfo info) {
	this->info = PlantInfo(info);
}

/**
 * @brief sets the water that the plant needs
 * 
 * @param water 
 */
void Plant::setWater(int water) {
	info.setWater(water);
}

/**
 * @brief sets the sun that the plant needs
 * 
 * @param sun 
 */
void Plant::setSun(int sun) {
	info.setSun(sun);
}

/**
 * @brief sets the fertiliser plant needs 
 * 
 * @param fertiliser 
 */
void Plant::setFertiliser(int fertiliser) {
	info.setFertiliser(fertiliser);
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
int Plant::getWater() const {
	return info.getWater();
}

/**
 * @brief return the amount of sun that the  plant needs 
 * 
 * @return int 
 */

int Plant::getSun() const {
	return info.getSun();
}


/**
 * @brief returns the amount of fertiliser that the plant needs 
 * 
 * @return int 
 */
int Plant::getFertiliser() const {
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
	// TODO - implement Plant::attach
	throw "Not yet implemented";
}

void Plant::detach(Staff* s) {
	// TODO - implement Plant::detach
	throw "Not yet implemented";
}

void Plant::notify() {
	// TODO - implement Plant::notify
	throw "Not yet implemented";
}
