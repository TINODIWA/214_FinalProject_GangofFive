
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

StaffCo_ordination::StaffCo_ordination(Garden* g) : Nursery(g) {}

StaffCo_ordination::~StaffCo_ordination() {}

void StaffCo_ordination::sendMessage(string m, Staff* from, string type) {
  if(from == NULL) return;

  cout << "Manager is broadcasting to all staff to: " << m << endl;
  for (Staff* s : staff) {
    s->receive(m, from, this, type);
  }
}

void StaffCo_ordination::sendMessage(string m, Staff* to, Staff* from, string type) {
  if (to == NULL || (to->getType() != "Gardener" && to->getType() != "Sales" && to->getType() != "Admin")) return;
  if (from == NULL) return;

  cout << "Manager is asking " << to->getType() << " to: " << m << endl;

  to->receive(m, from, this, type);
}

void StaffCo_ordination::addStaff(Staff* s) {
  staff.push_back(s);
}
void StaffCo_ordination::removeStaff(Staff* s) {
  for (vector<Staff *>::iterator us = staff.begin(); us != staff.end(); us++)
    {
        if (*us == s)
        {
            staff.erase(us);
            return;
        }
    }
}
