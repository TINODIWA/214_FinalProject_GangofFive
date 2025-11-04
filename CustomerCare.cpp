/**
 * @file CustomerCare.cpp
 * @author Unathi Tshakalisa
 * @brief Implementation of the CustomerCare class, which mediates interactions between customers and staff in the nursery
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

/**
 * @brief Construct a new CustomerCare object
 */
CustomerCare::CustomerCare() : Nursery() {}

/**
 * @brief Construct a new CustomerCare object with a garden plot
 * @param g Pointer to the garden plot to manage
 */
CustomerCare::CustomerCare(GardenPlot* g) : Nursery(g) {}

/**
 * @brief Destroy the CustomerCare object
 */
CustomerCare::~CustomerCare() {}

/**
 * @brief Add a staff member to customer care
 * @param s Pointer to the staff member to add
 */
void CustomerCare::addStaff(Staff* s) {
  if (s) {
    staff.push_back(s);
    s->setNursery(this);
  }
}

/**
 * @brief Remove a staff member from customer care
 * @param s Pointer to the staff member to remove
 */
void CustomerCare::removeStaff(Staff* s) {
  for (auto it = staff.begin(); it != staff.end(); ++it) {
    if (*it == s) {
      staff.erase(it);
      return;
    }
  }
}

/**
 * @brief Add a customer to customer care
 * @param c Pointer to the customer to add
 */
void CustomerCare::addCustomer(Customer* c) {
  if (c) {
    customers.push_back(c);
    c->setNursery(this);
  }
}

/**
 * @brief Remove a customer from customer care
 * @param c Pointer to the customer to remove
 */
void CustomerCare::removeCustomer(Customer* c) {
  for (auto it = customers.begin(); it != customers.end(); ++it) {
    if (*it == c) {
      customers.erase(it);
      return;
    }
  }
}

/**
 * @brief Send a message to all staff members
 * @param m The message to send
 * @param from Pointer to the sender
 * @param type Type of the message
 */
void CustomerCare::sendMessage(std::string m, People* from, std::string type) {
  for (Staff* s : staff) {
    if (s) s->receive(m, from, this, type);
  }
}

/**
 * @brief Send a message to a specific person
 * @param m The message to send
 * @param to Pointer to the recipient
 * @param from Pointer to the sender
 * @param type Type of the message
 */
void CustomerCare::sendMessage(std::string m, People* to, People* from, std::string type) {
  if (!to) return;
  to->receive(m, from, this, type);
}

/**
 * @brief Get the name of the customer care department
 * @return The department name as a string
 */
string CustomerCare::getName() const {
  return "CustomerCare";
}

/**
 * @brief Set up the chain of responsibility for handling customer requests
 */
void CustomerCare::setChain() {
  Staff* base = this->findStaffByType("BaseStaff");
  Staff* gardener = this->findStaffByType("Gardening");
  Staff* sales = this->findStaffByType("Sales");
  Staff* manager = this->findStaffByType("Management");
  
  chainHead = base;
  base->setSuccessor(gardener);
  gardener->setSuccessor(sales);
  sales->setSuccessor(manager);
  manager->setSuccessor(NULL);
}

/**
 * @brief Process a customer request through the chain of responsibility
 * @param req The request to process
 * @param customer Pointer to the customer making the request
 */
void CustomerCare::notify(Request req, Customer* customer) {
  // setChain(),
  if (chainHead) {
    chainHead->handleCustomer(req, customer);
  } else {
    for (Staff* s : staff) {
      if (s) s->receive("Customer request", customer, this, "CustomerRequest");
    }
  }
}
