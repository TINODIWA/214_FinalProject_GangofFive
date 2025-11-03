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
#include "Crop.h"
#include <functional>

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
 * Iterates through managed plants, checking their state
 * Calls handlePlant for dying plants, notifies manager for dead plants
 */
void Gardening::checkPlants() {
	for (int i = 0; i < plants.size(); i++) {
		if (plants[i]) {
			std::string state = plants[i]->getState();
			std::cout << "Checking plant: " << plants[i]->getName() 
			          << " - State: " << state << std::endl;
			
			if (state == "Dying") {
				handlePlant(plants[i]);
			} 
			else if (state == "Dead") {
				std::string message = "Plant " + plants[i]->getName() + " has died.";
				send(message, nullptr, getNursery(), "Manager");
			}
		}
	}
}

void Gardening::handleCustomer(Request* req) {
  if (req->getRequest() == "Advice") {
    std::cout << ". I am " + name +
                     " and I will be assisting you.\n nursery->getGarden()->viewAll() \n\tPlease "
                     "enter the number of the plant you'd like advice on below.\n\t Number:"
              << std::endl;
    int plantId;
    cin >> plantId;

    while (plantId < 1 || plantId > 5) {
      cout << "\n\t nursery->getGarden()->viewAll() \n Please enter a valid number: " << endl;
      cin >> plantId;
    }

    cout << "Plant advice of garden.getAdvice().... \n Would you like: 1)Advice on another plant.\n\t2)Create an "
            "order.\n\t3)Return an old "
            "order\n\t4)Repurchase an old order. \n Please enter a number: ";

    int request;
    cin >> request;

    string pass = "Passing your request on...";
    switch (request) {
      case 1:
        cout << "Plant advice of garden.getAdvice()...." << endl;
        break;
      case 2:
        cout << pass << endl;
        ((CustomerCare*)nursery)->notify(new Request("Order"));
        break;
      case 3:
        cout << pass << endl;
        ((CustomerCare*)nursery)->notify(new Request("Return"));
        break;
      case 4:
        cout << pass << endl;
        ((CustomerCare*)nursery)->notify(new Request("Repurchase"));
        break;
      default:
        cout << "Error in request case switch!" << endl;
        break;
    }
  } else if (successor) {
    successor->handleCustomer(req);
  } else {
    std::cout << "No staff could handle the request." << std::endl;
  }
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



