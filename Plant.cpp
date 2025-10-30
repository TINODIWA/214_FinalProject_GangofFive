#include "Plant.h"


/**
 * @brief Construct a new Plant:: Plant object
 * 
 */
Plant::Plant() {
	info = PlantInfo();
	care = NULL;
	checked = false;
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
	this->care = other.care;
	this->checked = other.checked;
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
	care = NULL;
	checked = false;
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

/**
 * @brief Attach a Staff observer to this Plant
 * @param s Pointer to the Staff observer to attach
 */
void Plant::attach(Staff* s) {
    if (s != NULL) {
        observers.push_back(s);
    }
}

/**
 * @brief Detach a Staff observer from this Plant
 * @param s Pointer to the Staff observer to remove
 */
void Plant::detach(Staff* s) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == s) {
            observers.erase(it);
            break;
        }
    }
}

/**
 * @brief Notify all attached observers of a state change
 * Calls update() on each attached Staff observer
 */
void Plant::notify() {
    for (Staff* observer : observers) {
        if (observer != NULL) {
            observer->update(this);
        }
    }
}

void Plant::addPlant(Plant *p){}

/**
 * @brief Set the PlantCare strategy for this Plant
 * @param strategy Pointer to the PlantCare strategy to use
 */
void Plant::setPlantCare(PlantCare* strategy) {
    this->care = strategy;
}

/**
 * @brief Get the current PlantCare strategy
 * @return Pointer to the current PlantCare strategy
 */
PlantCare* Plant::getPlantCare() const {
    return care;
}

/**
 * @brief Set the checked status of the Plant
 * @param v Boolean value indicating if plant has been checked
 */
void Plant::setChecked(bool v) {
    this->checked = v;
}

/**
 * @brief Get the checked status of the Plant
 * @return Boolean indicating if plant has been checked
 */
bool Plant::isChecked() const {
    return checked;
}