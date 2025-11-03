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
#include "CustomerCare.h"
#include "Customer.h"

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
      std::cout << "Checking plant: " << plants[i]->getName() << " - State: " << state << std::endl;

      if (state == "Dying") {
        handlePlant(plants[i]);
      } else if (state == "Dead") {
        std::string message = "Plant " + plants[i]->getName() + " has died.";
        send(message, nullptr, getNursery(), "Manager");
      }
    }
  }
}
void Gardening::handleCustomer(Request req, Customer* customer) {
  if (req.getRequest() == "Advice") {
    std::cout << "I am " << name << " and I will be assisting you.\n"
              << "nursery->getGarden()->viewAll()\n"
              << "\tPlease enter the number of the plant you'd like advice on below.\n";

    int plantId =
        readIntInRange(1, 5, "\tNumber: ", "\n\t nursery->getGarden()->viewAll() \n Please enter a valid number: ");

    std::cout << "Plant advice of garden.getAdvice().... \n"
              << "Would you like:\n"
              << "\t1) Advice on another plant.\n"
              << "\t2) Create an order.\n"
              << "\t3) Return an old order.\n"
              << "\t4) Repurchase an old order.\n";

    int next = readIntInRange(1, 4, "Please enter a number: ", "Please enter a valid number (1-4): ");

    const std::string pass = "Passing your request on...";
    switch (next) {
      case 1:
        std::cout << "Plant advice of garden.getAdvice()....\n";
        break;
      case 2:
        std::cout << pass << "\n";
        ((CustomerCare*)nursery)->notify( Request("Order"),customer);
        break;
      case 3:
        std::cout << pass << "\n";
        ((CustomerCare*)nursery)->notify(Request("Return"),customer);
        break;
      case 4:
        std::cout << pass << "\n";
        ((CustomerCare*)nursery)->notify( Request("Repurchase"),customer);
        break;
      default:
        std::cout << "Error in request case switch!\n";
        break;
    }
  } else if (successor) {
    successor->handleCustomer(req, customer);
  } else {
    std::cout << "No staff could handle the request.\n";
  }
}

void Gardening::receive(string m, People* from, Nursery* group, string type) {
  if (!(from && group)) return;

  cout << this->getName() << "(Gardening) received message from " << from->getName() << "( " << static_cast<Staff*>(from)->getType() << " ): " << m << " [type: " << type << "]"
       << endl;
  if (dynamic_cast<Staff*>(from)->getType() == "Manager" && group->getName() == "StaffCo_ordination") {
    if (type == "CheckPlants") {
      this->checkPlants();
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
    int req = water[1];
    if (curr < req) {
      int change = req - curr;
      int newCurr = wc->apply(curr, req, 1);
      p->updateWaterLevel(newCurr);
    }
  }

  vector<int> fert = p->getFertiliser();
  PlantCare* fc = p->getFertiliserCare();
  if (fc != nullptr && fert.size() >= 2) {
    int curr = fert[0];
    int req = fert[1];
    if (curr < req) {
      int change = req - curr;
      int newCurr = fc->apply(curr, req, 1);
      p->updateFertiliserLevel(newCurr);
    }
  }
}
