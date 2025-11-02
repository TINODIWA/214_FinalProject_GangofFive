/**
 * @file Staff.cpp
 * @author Nathan Chisadza, Dominiqu Nigatu
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Staff.h"

/**
 * @brief Construct a new Staff:: Staff object
 */
Staff::Staff() : People(), successor(NULL) {}

/**
 * @brief Construct a new Staff:: Staff object
 *
 * @param n Mediator this staff will communicate through
 * @param name name of staff member
 */
Staff::Staff(Nursery* n, string name) : People(n, name), successor(NULL) {}

/**
 * @brief Construct a new Staff:: Staff object
 *
 * @param other Staff to copy from
 */
Staff::Staff(const Staff* other) : People(*other) {
  if (other) {
    this->name = other->name;
    this->successor = other->successor;
  }
}

/**
 * @brief Destroy the Staff:: Staff object
 */
Staff::~Staff() {
  this->successor = NULL;
}

/**
 * @brief Sets the next staff member in the chain of responsibility
 *
 * @param succ Next staff member
 */
void Staff::setSuccessor(Staff* succ) {
  this->successor = succ;
}

/**
 * @brief Handles customer requests by passing them to the successor if exists
 *
 * @param req Customer request to handle
 */
void Staff::handleCustomer(Request* req) {
  if (this->successor) {
    this->successor->handleCustomer(req);
  }
}

bool Staff::operator==(const Staff& other) const {
  if (getName() != other.getName()) {
    return false;
  }

  return true;
}
