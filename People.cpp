/**
 * @file People.cpp
 * @author Nathan Chisadza, Unathi Tshakalisa
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "People.h"

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
  delete nursery;
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

string People::getName() const {
  return name;
}

Nursery* People::getNursery() const {
  return nursery;
}

void People::setName(const string& name) {
  this->name = name;
}

void People::setNursery(Nursery* n) {
  this->nursery = n;
}

