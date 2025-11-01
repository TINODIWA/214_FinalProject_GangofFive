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



Sales::Sales(Nursery* n, std::string name) : Roles(n, name) {}

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
  // TODO(user) - implement Sales::handleCustomer
  throw "Not yet implemented";
}

void Sales::handlePlant(Plant* p) {

}
