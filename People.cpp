/**
 * @file People.cpp
 * @author Nathan Chisadza, Unathi Tshakalisa
 * @brief Implementation of the People class which serves as a base class for all persons in the nursery system, handling communication through mediator
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "People.h"
#include "CustomerCare.h"

/**
 * @brief Construct a new People:: People object
 *
 * @param n Mediator this person will communicate through
 * @param name name of person
 */
People::People(Nursery* n, string name) : nursery(n), name(name) {}

/**
 * @brief Construct a new People:: People object
 *
 */
People::People() : nursery(nullptr), name("") {}

/**
 * @brief Construct a new People:: People object
 *
 * @param other People to copy from
 */
People::People(const People* other) {
  if (other) {
    this->nursery = other->nursery;
    this->name = other->name;
  }
}

/**
 * @brief Destroy the People:: People object
 *
 */
People::~People() {
  nursery = NULL;
}

/**
 * @brief Sends a message to the group via the mediator
 *
 * @param m Message to send
 * @param group Mediator to send through
 * @param type Type of message
 */
void People::send(string m, Nursery* group, string type) {
  if(group) {
    group->sendMessage(m, this, type);
  }
}

/**
 * @brief Sends a message to a specific person via the mediator
 *
 * @param m Message to send
 * @param to Recipient of the message
 * @param group Mediator to send through
 * @param type Type of message
 */
void People::send(string m, People* to, Nursery* group, string type) {
  if(to && group) {
    group->sendMessage(m, to, this, type);
  }
}

/**
 * @brief Get the name of the person
 * @return string The person's name
 */
string People::getName() const {
  return name;
}

/**
 * @brief Get the nursery mediator for this person
 * @return Nursery* Pointer to the nursery mediator
 */
Nursery* People::getNursery() const {
  return nursery;
}

/**
 * @brief Set the name of the person
 * @param name The new name to set
 */
void People::setName(const string& name) {
  this->name = name;
}

/**
 * @brief Set the nursery mediator for this person
 * @param n Pointer to the new nursery mediator
 */
void People::setNursery(Nursery* n) {
  this->nursery = n;
}
