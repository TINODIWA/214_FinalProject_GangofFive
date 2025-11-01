/**
 * @file Staff.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Staff.h"

void Staff::handlePlant(Plant* p) {
  // TODO(user) - implement Staff::handlePlant
  // throw "Not yet implemented";
}

void Staff::handleCustomer(Request* req) {
  // TODO(user) - implement Staff::handleCustomer
  // throw "Not yet implemented";
}

Staff::Staff(string name) : People(nullptr,name),successor(nullptr) {
  // TODO(user) - implement Staff::Staff
  // throw "Not yet implemented";
}

Staff::Staff(const Staff* other) : People(*other) {
  if (other) {
    this->level = other->level;
    this->successor = new Staff(*other->successor);

    vector<string>::const_iterator it = other->responsibilities.begin();

    while (it != other->responsibilities.end()) {
      responsibilities.push_back(*it);
    }
  }
}

string Staff::JobDesc() {
  // TODO(user) - implement Staff::JobDesc
  // throw "Not yet implemented";
}

string Staff::getType() {
  // TODO(user) - implement Staff::getType
  // throw "Not yet implemented";
}

string Staff::getLevel() const {
  return level;
}

vector<string> Staff::getResponsibilities() const {
  return responsibilities;
}

bool Staff::operator==(const Staff& other) const {
  if (getName() != other.getName()) {
    return false;
  }
  if (level != other.level) {
    return false;
  }
  if (responsibilities != other.responsibilities) {
    return false;
  }

  return true;
}
