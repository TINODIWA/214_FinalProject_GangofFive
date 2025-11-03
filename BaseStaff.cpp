/**
 * @file BaseStaff.cpp
 * @author Nathan Chisadza, Unathi Tshakalisa, Dominiqu Nigatu
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "BaseStaff.h"
#include "CustomerCare.h"
#include "Customer.h"

BaseStaff::BaseStaff() : Staff() {}

BaseStaff::BaseStaff(Nursery* n, std::string name) : Staff(n, name) {}

BaseStaff::~BaseStaff() {}

std::string BaseStaff::jobDesc() {
  return "Base staff member responsible for general tasks such as greeting customers and showing customers the plants.";
}

/**
 * @brief Get the staff type for this object.
 */
std::string BaseStaff::getType() {
  return "BaseStaff";
}

void BaseStaff::receive(std::string m, People* from, Nursery* group, std::string type) {
  std::cout << "[BaseStaff::receive] from: " << (from ? from->getName() : std::string("unknown")) << ", type: " << type
            << ", msg: " << m << std::endl;
}

void BaseStaff::update(Plant* p) {}       // stubbed
void BaseStaff::handlePlant(Plant* p) {}  // stubbed

void BaseStaff::handleCustomer(Request req, Customer* customer) {
  if (!customer) {
    std::cout << "Error: No customer assigned. Cannot proceed.\n";
    return;
  }

  if (!nursery) {
    std::cout << "Error: Nursery is not available. Please try again later.\n";
    return;
  }
  if (req.getRequest() == "Enter") {
    std::cout << "Welcome to the GoF Nursery, " << customer->getName() << ". I am " << name
              << " and I will be helping you today.\n";

    bool gardenShown = false;
    bool finished = false;

    while (!finished) {
      if (!gardenShown) {
        std::cout << "\nWould you like to:\n"
                  << "\t1) View the Garden\n"
                  << "\t2) Create an Order.\n"
                  << "\t3) Request Plant Advice.\n"
                  << "\t4) Return an old order\n"
                  << "\t5) Repurchase an old order.\n";
      } else {
        std::cout << "\nWhat would you like to do next?\n"
                  << "\t2) Create an Order.\n"
                  << "\t3) Request Plant Advice.\n"
                  << "\t4) Return an old order\n"
                  << "\t5) Repurchase an old order.\n";
      }


      int minOption = gardenShown ? 2 : 1;
      int choice =
          readIntInRange(minOption, 5, "Please enter the number below.\nNumber: ", "\nPlease enter a valid number: ");

      switch (choice) {
        case 1: {
      
          std::cout << "\nLovely, this is our garden.\n\n" << nursery->getGarden()->print() << "\n" << std::endl;

          gardenShown = true;  
          break;
        }
        case 2:
          std::cout << "\nPassing your request on to create an order...\n";
          ((CustomerCare*)nursery)->notify(Request("Order"), customer);
          finished = true;
          break;

        case 3:
          std::cout << "\nPassing your request on for plant advice...\n";
          ((CustomerCare*)nursery)->notify(Request("Advice"), customer);
          finished = true;
          break;

        case 4:
          std::cout << "\nPassing your request on to process a return...\n";
          ((CustomerCare*)nursery)->notify(Request("Return"), customer);
          finished = true;
          break;

        case 5:
          std::cout << "\nPassing your request on to repurchase an old order...\n";
          ((CustomerCare*)nursery)->notify(Request("Repurchase"), customer);
          finished = true;
          break;

        default:
          std::cout << "Unexpected option. Please try again.\n";
          break;
      }
    }
  } else if (successor) {
    successor->handleCustomer(req, customer);
  } else {
    std::cout << "No staff could handle the request.\n";
  }
}
