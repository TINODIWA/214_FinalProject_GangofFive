/**
 * @file CustomerCare.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "CustomerCare.h"
#include "People.h"
#include "Staff.h"
#include "Customer.h"
#include "Request.h"

CustomerCare::CustomerCare() : Nursery() {}

CustomerCare::CustomerCare(Garden* g) : Nursery(g) {}

CustomerCare::~CustomerCare(){

}

void CustomerCare::addStaff(Staff* s) {
  if (s) staff.push_back(s);
}

void CustomerCare::removeStaff(Staff* s) {
  for (auto it = staff.begin(); it != staff.end(); ++it) {
    if (*it == s) { staff.erase(it); return; }
  }
}

void CustomerCare::addCustomer(Customer* c) {
  if (c) customers.push_back(c);
}

void CustomerCare::removeCustomer(Customer* c) {
  for (auto it = customers.begin(); it != customers.end(); ++it) {
    if (*it == c) { customers.erase(it); return; }
  }
}

void CustomerCare::sendMessage(std::string m, People* from, std::string type) {
  // Broadcast-like semantics aren’t typical for customer care; if it’s a request, kick off CoR.
  // If a chain is configured, route as a request. Otherwise, notify all staff.
  if (chainHead && type == "CustomerRequest") {
    // We don't construct Request here to avoid guessing constructors; provide routeRequest API instead.
    // As a fallback, notify staff of the message.
  }
  for (Staff* s : staff) {
    if (s) s->receive(m, from, this, type);
  }
}

void CustomerCare::sendMessage(std::string m, People* to, People* from, std::string type) {
  if (!to) return;
  to->receive(m, from, this, type);
}

string CustomerCare::getName() const {
  return "CustomerCare";
}

void CustomerCare::setChain(const std::vector<Staff*>& order) {
  if (order.empty()) { chainHead = NULL; return; }
  // Link successors in the provided order
  for (size_t i = 0; i + 1 < order.size(); ++i) {
    if (order[i]) order[i]->setSuccessor(order[i+1]);
  }
  // Last in chain has no successor
  if (order.back()) order.back()->setSuccessor(NULL);
  chainHead = order.front();
}

void CustomerCare::routeRequest(Request* req, Customer* from) {
  if (chainHead && req) {
    chainHead->handleCustomer(req);
  } else {
    // Fallback: notify staff via receive
    for (Staff* s : staff) {
      if (s) s->receive("Customer request", from, this, "CustomerRequest");
    }
  }
}

void CustomerCare::notify(Request* req) {
  if (chainHead && req) {
    chainHead->handleCustomer(req);
  }
}
