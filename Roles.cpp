/**
 * @file Roles.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Roles.h"

Roles::Roles(Nursery* n, string name) : Staff(n, name) {}

Roles::~Roles() {
  for (Staff* s : staff) {
    delete s;
  }
  staff.clear();
}

std::string Roles::jobDesc() {
  return "Base staff member responsible for general tasks such as greeting customers and showing customers the plants.";
}

std::string Roles::getType() {
  return "BaseStaff";
}
