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

Roles::Roles(Nursery* n, string name, Staff* s) : Staff(n, name), staff(s) {}

Roles::~Roles() {
  // Important: Roles does not own pointers in 'staff' by default.
  // They may be managed elsewhere (e.g., mediator), so avoid double-deletes.
  // Do not call methods like clear() on a raw pointer; reset to nullptr if desired.
  staff = NULL;
}


std::string Roles::jobDesc() {
  return "Base staff member responsible for general tasks such as greeting customers and showing customers the plants.";
}

std::string Roles::getType() {
  return "BaseStaff";
}

void Roles::update(Plant* p){}

void Roles::receive(string m, People* from, Nursery* group, string type) {
}
