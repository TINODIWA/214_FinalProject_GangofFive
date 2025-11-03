/**
 * @file Sales.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Sales.h"
#include <iostream>
#include "CustomerCare.h"
#include "Customer.h"

Sales::Sales(Staff* s) : Roles(s->getNursery(), s->getName(), s) {}

Sales::~Sales() {}

string Sales::getType() {
  return Roles::getType() + ": Sales";
}

/**
 * @brief Get the job description for this staff role.
 */
std::string Sales::jobDesc() {
  return Roles::jobDesc() + "\nAdditionally, Sales staff are responsible for assisting customers with their purchases.";
}

void Sales::handleCustomer(Request req, Customer* customer) {
  if (req.getRequest() == "Order") {
    std::cout
      << "I am " << name << " and I will be assisting you.\n"
      << "nursery->getGarden()->viewAvailable()\n"
      << "\tPlease enter the number of the plant you'd like to add below, followed by the quantity.\n"
      << "\te.g.) Number: 01 \nQuantity: 5\n";

    int plantId = readIntInRange(
      1, 5,
      "\tNumber: ",
      "\n\t nursery->getGarden()->viewAll() \n Please enter a valid number: "
    );

    int quantity = readIntInRange(
      1, 1000000,
      "Quantity: ",
      "Please enter a valid quantity (>=1): "
    );

    std::cout
      << "Would you like to:\n"
      << "\t1) Add more plants.\n"
      << "\t2) Remove a plant from order.\n"
      << "\t3) Place your order.\n";

    int next = readIntInRange(
      1, 3,
      "Please enter a number: ",
      "Please enter a valid number (1-3): "
    );

    switch (next) {
      case 1: std::cout << "Adding more plants logic\n"; break;
      case 2: std::cout << "Removing plants logic\n";    break;
      case 3:
        std::cout << "Purchasing logic. Thanks for shoppig with GOF Nursery. "
                     "Advice on your plants is attached in the receipt:)\n";
        break;
      default:
        std::cout << "Error in request case switch!\n";
        break;
    }
  } else if (req.getRequest() == "Repurchase") {
    std::cout << "repurchaing logic\n";
  } else if (successor) {
    successor->handleCustomer(req,customer);
  } else {
    std::cout << "No staff could handle the request.\n";
  }
}


void Sales::receive(string m, People* from, Nursery* group, string type) {
  if (!(from || group)) return;
  std::cout << "[Sales::receive] from: " << (from ? from->getName() : std::string("unknown")) << ", type: " << type
            << ", msg: " << m << std::endl;
}

void Sales::update(Plant* p) {}       // stubbed
void Sales::handlePlant(Plant* p) {}  // stubbed