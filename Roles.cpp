/**
 * @file Roles.cpp
 * @author Domique Nigatu, Ryan Liao, Nathan Chisadza
 * @brief Implementation of the Roles class, a base class for staff roles in the nursery system
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Roles.h"


/**
 * @brief Construct a new Roles object
 * @param n Pointer to the nursery
 * @param name Name of the staff member
 * @param s Pointer to the staff member
 */
Roles::Roles(Nursery* n, string name, Staff* s) : Staff(n, name), staff(s) {}


/**
 * @brief Destroy the Roles object
 */
Roles::~Roles() {
  if (staff) {
    delete staff;
    staff = NULL;
  }
}


/**
 * @brief Get the job description for this staff role
 * @return std::string The job description
 */
std::string Roles::jobDesc() {
  return "Base staff member responsible for general tasks such as greeting customers and showing customers the plants.";
}


/**
 * @brief Get the type of staff role
 * @return std::string The type of staff role
 */
std::string Roles::getType() {
  return "BaseStaff";
}


/**
 * @brief Update method for plant state changes (stub)
 * @param p Pointer to the plant that has been updated
 */
void Roles::update(Plant* p){}

/**
 * @brief Receive and handle messages from other staff members (stub)
 * @param m The message content
 * @param from The sender of the message
 * @param group The nursery group context
 * @param type The type of message
 */
void Roles::receive(string m, People* from, Nursery* group, string type){}
