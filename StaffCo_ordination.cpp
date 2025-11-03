
/**
 * @file StaffCo_ordination.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "StaffCo_ordination.h"

// Assume all commands come from the manager for now

/**
 * @brief Construct a new StaffCo_ordination object
 */
StaffCo_ordination::StaffCo_ordination() : Nursery() {}

StaffCo_ordination::StaffCo_ordination(GardenPlot* g) : Nursery(g) {}

StaffCo_ordination::~StaffCo_ordination() {}

void StaffCo_ordination::sendMessage(string m, People* from, string type) {
  if (!from) return;
  cout << from->getName() << "[" << static_cast<Staff*>(from)->getType() << "] broadcasts: " << m << endl;
  for (Staff* s : staff) {
    if (s && s != static_cast<Staff*>(from)) {
      s->receive(m, from, this, type);
    }
  }
}

void StaffCo_ordination::sendMessage(string m, People* to, People* from, string type) {
  if (!to || !from) return;
  cout << from->getName() << "(" << static_cast<Staff*>(from)->getType() << ") -> " << to->getName() << "(" << static_cast<Staff*>(to)->getType() << "): " << m << endl;
  to->receive(m, from, this, type);
}

void StaffCo_ordination::addStaff(Staff* s) {
  if (s) staff.push_back(s);
}

void StaffCo_ordination::removeStaff(Staff* s) {
  for (vector<Staff*>::iterator it = staff.begin(); it != staff.end(); ++it) {
    if (*it == s) {
      staff.erase(it);
      return;
    }
  }
}

void StaffCo_ordination::addCustomer(Customer* c) {
  cout << "Customers not allowed in StaffCo_ordination nursery." << endl;
}

void StaffCo_ordination::removeCustomer(Customer* c) {
  cout << "Customers not allowed in StaffCo_ordination nursery." << endl;
}

string StaffCo_ordination::getName() const {
  return "StaffCo_ordination";
}
