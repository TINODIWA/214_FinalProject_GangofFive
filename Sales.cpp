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

void Sales::handleCustomer(Request* req) {
  if (req->getRequest() == "Sales") {
    std::cout << ". I am " + name +
                     " and I will be assisting you.\n nursery->getGarden()->viewAvailable() \n\tPlease "
                     "enter the number of the plant you'd like to add below, followed by the quantity. \neg)Number: 01 "
                     "\nQuantity: 5 \n\t Number:"
              << std::endl;
    int plantId;
    cin >> plantId;

    while (plantId < 1 || plantId > 5) {
      cout << "\n\t nursery->getGarden()->viewAll() \n Please enter a valid number: " << endl;
      cin >> plantId;
    }

    int quantity;
    cout << "Quantity: " << endl;
    cin >> quantity;

    cout << "Would you like to: \n\t1)Add more plants.\n\t2)Remove a plant from order.\n\t3)Place your order. \n Please enter a number: ";

    int request;
    cin >> request;

    string pass = "Passing your request on...";
    switch (request) {
      case 1:
        cout << "Adding more plants logic" << endl;
        break;
      case 2:
        cout <<"Removing plants logic"<< endl;
        break;
      case 3:
        cout << "Purchasing logic. Thanks for shoppig with GOF Nursery. Advice on your plants is attached in th receipt:)" << endl;
        break;
      default:
        cout << "Error in request case switch!" << endl;
        break;
    }
  } else if (req->getRequest() == "Repurchase") {
    cout << "repurchaing logic" << endl;
  } else if (successor) {
    successor->handleCustomer(req);
  } else {
    std::cout << "No staff could handle the request." << std::endl;
  }
}

void Sales::handlePlant(Plant* p) {

}

void Sales::receive(string m, People* from, Nursery* group, string type) {
  if(!(from || group)) return;
  
}
