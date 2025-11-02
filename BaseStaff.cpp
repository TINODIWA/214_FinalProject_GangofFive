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

BaseStaff::BaseStaff() : Staff() {}

BaseStaff::BaseStaff(Nursery* n, std::string name) : Staff(n, name) {}

BaseStaff::~BaseStaff() {}

string BaseStaff::jobDesc() {
  return "Base staff member responsible for general tasks such as greeting customers and showing customers the plants.";
}

/**
 * @brief Get the staff type for this object.
 */
std::string BaseStaff::getType() {
  return "BaseStaff";
}

void BaseStaff::handleCustomer(Request* req) {
  if (req->getRequest() == "Enter") {
    std::cout << "Welcome to the GOF Nursery. I am " + name +
                     " and I will be helping you today.\n Would you like to:\n\t1)View the Garden\n\t2)Create an "
                     "order.\n\t3)Request Plant Advice.\n\t4)Return an old order\n\t5)Repurchase an old order.\nPlease "
                     "enter the number below.\n Number:"
              << std::endl;
    int request;
    cin >> request;

    while (request < 1 || request > 5) {
      cout << "\n\t1)View the Garden\n\t2)Create an order.\n\t3)Request Plant Advice.\n\t4)Return an old "
              "order\n\t5)Repurchase an old order. \n Please enter a valid number: "
           << endl;
      cin >> request;
    }

    string pass = "Passing your request on...";
    switch (request) {
      case 1:
        cout <<"Lovely, this is our garden.\n nursery->getGarden()->print()" << endl;
        break;
      case 2:
        cout << pass << endl;
        ((CustomerCare*)nursery)->notify(new Request("Order"));
        break;
      case 3:
        cout << pass << endl;
        ((CustomerCare*)nursery)->notify(new Request("Advice"));
        break;
      case 4:
        cout << pass << endl;
        ((CustomerCare*)nursery)->notify(new Request("Return"));
        break;
      case 5:
        cout << pass << endl;
        ((CustomerCare*)nursery)->notify(new Request("Repurchase"));
        break;
      default:
        cout<<"Error in request case switch!"<<endl;
        break;
    }
  } else if (successor) {
    successor->handleCustomer(req);
  } else {
    std::cout << "No staff could handle the request." << std::endl;
  }
}

void BaseStaff::handlePlant(Plant* p) {
  // TODO(dom) - implement BaseStaff::handlePlant
  //throw "Not yet implemented";
}

void BaseStaff::receive(string m, People* from, Nursery* group, string type) {}
