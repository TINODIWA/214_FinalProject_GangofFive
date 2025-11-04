/**
 * @file BaseStaff.cpp
 * @author Nathan Chisadza, Unathi Tshakalisa, Dominiqu Nigatu
 * @brief Defines Implementation for BaseStaff.cpp
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "BaseStaff.h"
#include "CustomerCare.h"
#include "Customer.h"

/**
 * @brief Construct a new Base Staff object
 */
BaseStaff::BaseStaff() : Staff() {}

/**
 * @brief Construct a new Base Staff object
 * @param n The nursery where the staff member works
 * @param name The name of the staff member
 */
BaseStaff::BaseStaff(Nursery* n, std::string name) : Staff(n, name) {}

/**
 * @brief Destroy the Base Staff object
 */
BaseStaff::~BaseStaff() {}

/**
 * @brief Get the job description for this staff role
 * @return The job description as a string
 */
std::string BaseStaff::jobDesc() {
  return "Base staff member responsible for general tasks such as greeting customers and showing customers the plants.";
}

/**
 * @brief Get the staff type for this object
 * @return The staff type as a string
 */
std::string BaseStaff::getType() {
  return "BaseStaff";
}

/**
 * @brief Receive a message from another staff member or group
 * @param m The message content
 * @param from The sender of the message
 * @param group The nursery group involved
 * @param type The type of message
 */
void BaseStaff::receive(std::string m, People* from, Nursery* group, std::string type) {
  std::cout << "[BaseStaff::receive] from: " << (from ? from->getName() : std::string("unknown")) << ", type: " << type
            << ", msg: " << m << std::endl;
}

/**
 * @brief Update the staff member's state based on plant changes
 * @param p The plant that triggered the update
 */
void BaseStaff::update(Plant* p) {}       // stubbed

/**
 * @brief Handle plant-related tasks
 * @param p The plant to handle
 */
void BaseStaff::handlePlant(Plant* p) {}  // stubbed

/**
 * @brief Handle a customer request
 * @param req The request to handle
 * @param customer The customer making the request
 */
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
                  << "\t4) Place a complaint\n"
                  << "\t5) Repurchase an old order.\n"
                  << "\t6) Exit Nursery.\n";
      } else {
        std::cout << "\nWhat would you like to do next?\n"
                  << "\t2) Create an Order.\n"
                  << "\t3) Request Plant Advice.\n"
                  << "\t4) Place a complaint\n"
                  << "\t5) Repurchase an old order.\n"
                  << "\t6) Exit Nursery.\n";
      }


      int minOption = gardenShown ? 2 : 1;
      int choice =
          readIntInRange(minOption, 6, "Please enter the number below.\nNumber: ", "\nPlease enter a valid number: ");

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
          std::cout << "\nPassing your request on to process a complaint...\n";
          ((CustomerCare*)nursery)->notify(Request("Complaint"), customer);
          finished = true;
          break;

        case 5:
          std::cout << "\nPassing your request on to repurchase an old order...\n";
          ((CustomerCare*)nursery)->notify(Request("Repurchase"), customer);
          finished = true;
          break;

        case 6:
          std::cout << "\nThanks for visiting GoF Nursery!!\n";
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
