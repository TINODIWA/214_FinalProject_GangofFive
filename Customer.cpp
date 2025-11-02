
/**
 * @file Customer.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Customer.h"
#include "CustomerCare.h"

Customer::Customer(string name): People(NULL, name) {
  // TODO(unathi,nathan,ryan) - implement Customer::Customer
  // throw "Not yet implemented";
}

Customer::~Customer() {}

Customer::Customer(const Customer* other) {
  // if (other)
  // this->order = new Order(*other->order);
}

void Customer::makeReq(Request* req) {
  if (!req) return;
  Nursery* n = getNursery();
  if (n) {
    if (CustomerCare* cc = dynamic_cast<CustomerCare*>(n)) {
      cc->routeRequest(req, this);
    } else {
      // Fallback to message-based mediation
      send(req->getRequest(), n, "CustomerRequest");
    }
  } else {
    std::cout << "No customer care mediator set for customer: " << getName() << std::endl;
  }
}

