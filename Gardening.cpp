/**
 * @file Gardening.cpp
 * @author Unathi Tshkalisa, Nathan Chisadza, Dominique Nigatu, Ryan Liao
 * @brief Implementation of the Gardening role class, which handles plant maintenance, customer advice, and plant care strategies
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

/**
 * @brief Destroy the Gardening object
 */
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

/**
 * @brief Handle customer requests for plant advice
 * @param req The customer's request
 * @param customer Pointer to the customer making the request
 */
void Gardening::handleCustomer(Request req, Customer* customer) {
  if (!customer) {
    std::cout << "Error: No customer assigned. Cannot proceed.\n";
    return;
  }

  if (!nursery) {
    std::cout << "Error: Nursery is not available. Please try again later.\n";
    return;
  }

  if (req.getRequest() == "Advice") {
    std::cout << "\nI am " << name << " and I will be assisting you.\n\n";

    bool askAgain = true;
    while (askAgain) {
      auto inventory = nursery->getGarden()->viewAll();

      if (inventory.empty()) {
        std::cout << "There are currently no plants in the garden inventory.\n";
        return;
      }

      std::string inventoryList = printAll(inventory);
      std::cout << inventoryList << "\tPlease enter the number of the plant you'd like advice on below.\n";

      int maxIndex = static_cast<int>(inventory.size());
      int plantId = readIntInRange(1, maxIndex, "\tNumber: ", inventoryList + "\nPlease enter a valid number: ");

      auto it = inventory.begin();
      // cout<< it->first<<endl;
      std::advance(it, plantId - 1);
      const std::string& plantName = it->first;

      Garden* plant = nursery->getGarden()->get(plantName);
      if (!plant) {
        std::cout << "Error: could not find plant \"" << plantName << "\" in the garden.\n";
        return;
      }

      Plant* plantPtr = dynamic_cast<Plant*>(plant);
      if (!plantPtr) {
        std::cout << "Error: plant is not of type Plant*\n";
        return;
      }

      std::cout << "\nAdvice for " << plantPtr->getName() << ":\n"
                << plantPtr->advice() << "\n\n"
                << "Would you like:\n"
                << "\t1) Advice on another plant.\n"
                << "\t2) Create an order.\n"
                << "\t3) Place a complaint\n"
                << "\t4) Repurchase an old order.\n"
                << "\t5) Exit Nursery.\n";

      int next = readIntInRange(1, 5, "Please enter a number: ", "Please enter a valid number (1-4): ");

      switch (next) {
        case 1:

          askAgain = true;
          break;

        case 2:
          std::cout << "\nPassing your request on to create an order...\n" << endl;
          ((CustomerCare*)nursery)->notify(Request("Order"), customer);
          askAgain = false;
          break;

        case 3:
          std::cout << "\nPassing your request on to process a return...\n" << endl;
          ((CustomerCare*)nursery)->notify(Request("Complaint"), customer);
          askAgain = false;
          break;

        case 4:
          std::cout << "\nPassing your request on to repurchase an old order...\n" << endl;
          ((CustomerCare*)nursery)->notify(Request("Repurchase"), customer);
          askAgain = false;
          break;

        case 5:
          std::cout << "\nThanks for visiting GoF Nursery!!\n";
          askAgain = false;
          break;

        default:
          std::cout << "Error in request case switch!\n";
          askAgain = false;
          break;
      }
    }
  } else if (successor) {
    successor->handleCustomer(req, customer);
  } else {
    std::cout << "No staff could handle the request.\n";
  }
}

/**
 * @brief Receive and handle messages from other staff members
 * @param m The message content
 * @param from Pointer to the sender
 * @param group Pointer to the nursery group
 * @param type The type of message
 */
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
