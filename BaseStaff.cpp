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
  if(req) {
    std::cout << "BaseStaff handled request: " << req->getRequest() << std::endl;
  } else if (successor) {
    successor->handleCustomer(req);
  } else {
    std::cout << "No staff could handle the request." << std::endl;
  }
}

void BaseStaff::handlePlant(Plant* p) {
  // TODO(dom) - implement BaseStaff::handlePlant
  throw "Not yet implemented";
}

void BaseStaff::receive(string m, People* from, Nursery* group, string type) {
  
}

 
