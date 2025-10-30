#include "Gardening.h"

/**
 * @brief Observer pattern update method
 * Called when an observed Plant's state changes
 * @param p Pointer to the Plant that changed state
 */
void Gardening::update(Plant* p) {
    if (p != NULL) {
        handlePlant(p);
    }
}


/**
 * @brief Get the type of staff role
 * @return String identifying this as a Gardening role
 */
string Gardening::getType() {
    return "Gardening";
}

/**
 * @brief Check and handle all plants under management
 * Iterates through all plants and calls handlePlant on each
 */
void Gardening::checkPlants() {
    for (Plant* p : plants) {
        if (p != NULL) {
            handlePlant(p);
        }
    }
}

string Gardening::handleCustomer(Request* req) {
	// TODO - implement Gardening::handleCustomer
	throw "Not yet implemented";
}

/**
 * @brief Handle care needs for a specific plant
 * Checks and updates water, sun, and fertiliser levels using PlantCare strategy
 * @param p Pointer to the Plant to handle
 */
void Gardening::handlePlant(Plant* p) {
    if (p == NULL) return;

    PlantCare* care = p->getPlantCare();
    if (care == NULL) {
        return;
    }

    vector<int> water = p->getWater();
    if (water.size() >= 2) {
        int currW = water[0];
        int reqW = water[1];
        if (currW < reqW) {
            int change = reqW - currW;
            int newW = care->changeAmount(currW, reqW, change);
            p->setWater(newW);
            p->setChecked(true);
        }
    }

	vector<int> sun = p->getSun();
    if (sun.size() >= 2) {
        int currS = sun[0];
        int reqS = sun[1];
        if (currS < reqS) {
            int change = reqS - currS;
            int newS = care->changeAmount(currS, reqS, change);
            p->setSun(newS);
            p->setChecked(true);
        }
    }

    vector<int> fertiliser = p->getFertiliser();
    if (fertiliser.size() >= 2) {
        int currF = fertiliser[0];
        int reqF = fertiliser[1];
        if (currF < reqF) {
            int change = reqF - currF;
            int newF = care->changeAmount(currF, reqF, change);
            p->setFertiliser(newF);
            p->setChecked(true);
        }
    }
}

Gardening::~Gardening()
{
}

/**
 * @brief Default constructor for Gardening class
 * Initializes a new Gardening staff member
 */
Gardening::Gardening() {
    // no-op
}

string Gardening::handleCustomer(Request* req) {
	// TODO - implement Gardening::handleCustomer
	throw "Not yet implemented";
}

