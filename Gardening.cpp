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
Gardening::Gardening() : Roles() {
}


/**
 * @brief Destroy the Gardening object.
 */
Gardening::~Gardening() {
}

/**
 * @brief Get the staff type for this object.
 */
std::string Gardening::getType() {
	return "Gardening";
}

/**
 * @brief Get the job description for this staff role.
 */
std::string Gardening::jobDesc() {
	return "Gardening staff responsible for plant care and maintenance.";
}

void Gardening::update() {
	// for (int i = 0; i < plants.size(); ++i) {
	// 	Plant* plant = plants[i];
	// 	if (plant) {
	// 		std::cout << "Updating plant: " << plant->getName() << std::endl;
	// 	}
	// }
}

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

void Gardening::handlePlant(Plant* p) {
    // if (p) {
    //     std::cout << "Gardening staff is taking care of plant: " << p->getName() << std::endl;
    // } else if (successor) {
    //     successor->handlePlant(p);
    // } else {
    //     std::cout << "No staff could handle the plant request." << std::endl;
    // }
}

