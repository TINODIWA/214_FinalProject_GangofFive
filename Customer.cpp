
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
  //req = Request("Enter");
  // order = NULL;
}

Customer::~Customer() {}//should probably deletee their orders

Customer::Customer(const Customer* other) {
  // if (other)
  // this->order = new Order(*other->order);
}

void Customer::makeReq(Request req) {

  Nursery* n = getNursery();
  if (n) {
    if (CustomerCare* cc = dynamic_cast<CustomerCare*>(n)) {
      cc->notify(req, this);
    } else {
      
      send(req.getRequest(), n, "CustomerRequest");
    }
  } else {
    std::cout << "No customer care mediator set for customer: " << getName() << std::endl;
  }
}

void Customer::receive(string m, People* from, Nursery* group, string type){}

