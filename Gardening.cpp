/**
 * @file Gardening.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Gardening.h"
#include "Request.h"
#include <iostream>
#include <algorithm>
#include "Plant.h"

/**
 * @brief Construct a new Gardening object.
 */
Gardening::Gardening(Staff* s) : Roles(s->getNursery(), s->getName(), s) {}


Gardening::~Gardening() {}

/**
 * @brief Get the staff type for this object.
 */
std::string Gardening::getType() {
	return Roles::getType() + ": Gardening";
}

/**
 * @brief Get the job description for this staff role.
 */
std::string Gardening::jobDesc() {
	return Roles::jobDesc() + "\nGardening staff responsible for plant care and maintenance and giving customers advice.";
}

/**
 * @brief Observer pattern update method
 * Called when an observed Plant notifies of state change
 * @param p Pointer to the Plant that changed state
 */
void Gardening::update(Plant* p) {
  if (p != nullptr) {
    handlePlant(p);
  }
}

/**
 * @brief Check and handle all plants under management
 * Iterates through managed plants calling handlePlant on each
 */
void Gardening::checkPlants() {
	// for (int i = 0; i < plants.size(); i++) {
	// 	if (plants[i]) {
	// 		std::cout << "Checking plant: " << plants[i]->getName() << std::endl;
	// 	}
	// }
}

void Gardening::handleCustomer(Request* req) {
    // if (req) {
    //     std::cout << "Gardening staff handled request: " << req->getRequest() << std::endl;
    // } else if (successor) {
    //     successor->handleCustomer(req);
    // } else {
    //     std::cout << "No staff could handle the request." << std::endl;
    // }
}

void Gardening::receive(string m, People* from, Nursery* group, string type) {
  for (Plant* p : plants) {
    if (p != nullptr) {
      handlePlant(p);
    }
  }
}

/**
 * @brief Handle plant care needs
 * Checks water, sun and fertiliser levels against required levels
 * Applies appropriate care strategy when levels are below required
 * @param p Pointer to the Plant to handle
 */
void Gardening::handlePlant(Plant* p) {
  if (p == nullptr) return;

  vector<int> water = p->getWater();
  PlantCare* wc = p->getWaterCare();
  if (wc != nullptr && water.size() >= 2) {
    int curr = water[0];
    int req  = water[1];
    if (curr < req) {
      int change = req - curr;
      int newCurr = wc->apply(curr, req, change);
      p->updateWaterLevel(newCurr);
    }
  }

  vector<int> sun = p->getSun();
  PlantCare* sc = p->getSunCare();
  if (sc != nullptr && sun.size() >= 2) {
    int curr = sun[0];
    int req  = sun[1];
    if (curr < req) {
      int change = req - curr;
      int newCurr = sc->apply(curr, req, change);
      p->updateSunLevel(newCurr);
    }
  }

  vector<int> fert = p->getFertiliser();
  PlantCare* fc = p->getFertiliserCare();
  if (fc != nullptr && fert.size() >= 2) {
    int curr = fert[0];
    int req  = fert[1];
    if (curr < req) {
      int change = req - curr;
      int newCurr = fc->apply(curr, req, change);
      p->updateFertiliserLevel(newCurr);;
    }
  }
}



