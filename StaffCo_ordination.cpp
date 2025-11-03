/**
 * @file StaffCo_ordination.cpp
 * @author Nathan Chisadza
 * @brief Implementation of the StaffCo_ordination class, which manages staff communication and coordination in the nursery system
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


/**
 * @brief Construct a new StaffCo_ordination object with a garden plot
 * @param g Pointer to the garden plot
 */
StaffCo_ordination::StaffCo_ordination(GardenPlot* g) : Nursery(g) {}


/**
 * @brief Destroy the StaffCo_ordination object
 */
StaffCo_ordination::~StaffCo_ordination() {}


/**
 * @brief Broadcast a message from one staff member to all others
 * @param m The message content
 * @param from The sender of the message
 * @param type The type of message
 */
void StaffCo_ordination::sendMessage(string m, People* from, string type) {
  if (!from) return;
  cout << from->getName() << "[" << static_cast<Staff*>(from)->getType() << "] broadcasts: " << m << endl;
  for (Staff* s : staff) {
    if (s && s != static_cast<Staff*>(from)) {
      s->receive(m, from, this, type);
    }
  }
}


/**
 * @brief Send a message from one staff member to another
 * @param m The message content
 * @param to The recipient of the message
 * @param from The sender of the message
 * @param type The type of message
 */
void StaffCo_ordination::sendMessage(string m, People* to, People* from, string type) {
  if (!to || !from) return;
  cout << from->getName() << "(" << static_cast<Staff*>(from)->getType() << ") -> " << to->getName() << "(" << static_cast<Staff*>(to)->getType() << "): " << m << endl;
  to->receive(m, from, this, type);
}


/**
 * @brief Add a staff member to the coordination group
 * @param s Pointer to the staff member to add
 */
void StaffCo_ordination::addStaff(Staff* s) {
  if (s) staff.push_back(s);
}


/**
 * @brief Remove a staff member from the coordination group
 * @param s Pointer to the staff member to remove
 */
void StaffCo_ordination::removeStaff(Staff* s) {
  for (vector<Staff*>::iterator it = staff.begin(); it != staff.end(); ++it) {
    if (*it == s) {
      staff.erase(it);
      return;
    }
  }
}


/**
 * @brief Attempt to add a customer (not allowed in StaffCo_ordination)
 * @param c Pointer to the customer
 */
void StaffCo_ordination::addCustomer(Customer* c) {
  cout << "Customers not allowed in StaffCo_ordination nursery." << endl;
}


/**
 * @brief Attempt to remove a customer (not allowed in StaffCo_ordination)
 * @param c Pointer to the customer
 */
void StaffCo_ordination::removeCustomer(Customer* c) {
  cout << "Customers not allowed in StaffCo_ordination nursery." << endl;
}


/**
 * @brief Get the name of the coordination group
 * @return string The name of the group
 */
string StaffCo_ordination::getName() const {
  return "StaffCo_ordination";
}
