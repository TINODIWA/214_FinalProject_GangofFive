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

void BaseStaff::handleCustomer(Request req) {
  if (req.getRequest() == "Enter") {
    std::cout << "Welcome to the GOF Nursery. I am " << name << " and I will be helping you today.\n"
              << "Would you like to:\n"
              << "\t1) View the Garden\n"
              << "\t2) Create an order.\n"
              << "\t3) Request Plant Advice.\n"
              << "\t4) Return an old order\n"
              << "\t5) Repurchase an old order.\n";

    int choice = readIntInRange(1, 5, "Please enter the number below.\nNumber: ",
                                "\n\t1)View the Garden\n\t2)Create an order.\n\t3)Request Plant Advice.\n\t4)Return an "
                                "old order\n\t5)Repurchase an old order.\nPlease enter a valid number: ");

    const std::string pass = "Passing your request on...";
    switch (choice) {
      case 1:
        std::cout << "Lovely, this is our garden.\n nursery->getGarden()->print()\n";
        break;
      case 2:
        std::cout << pass << "\n";
        // ((CustomerCare*)nursery)->notify(new Request("Order"));
        break;
      case 3:
        std::cout << pass << "\n";
        // ((CustomerCare*)nursery)->notify(new Request("Advice"));
        break;
      case 4:
        std::cout << pass << "\n";
        // ((CustomerCare*)nursery)->notify(new Request("Return"));
        break;
      case 5:
        std::cout << pass << "\n";
        // ((CustomerCare*)nursery)->notify(new Request("Repurchase"));
        break;
      default:
        std::cout << "Error in request case switch!\n";
        break;
    }
  } else if (successor) {
    successor->handleCustomer(req);
  } else {
    std::cout << "No staff could handle the request.\n";
  }
}
