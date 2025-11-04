/**
 * @file Nursery.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Nursery.h"
#include "Customer.h"
#include "Staff.h"

Nursery::Nursery() {}

Nursery::Nursery(Garden* g) : garden(g) {}

Nursery::~Nursery() {}

Nursery::Nursery(const Nursery& other) {
  // vector<vector<Plant*>>::const_iterator otherPlants = (other.garden).begin();
  Garden* otherGarden = other.garden;
  vector<Customer*>::const_iterator otherCustomer = (other.customers).begin();
  vector<Staff*>::const_iterator otherStaff = (other.staff).begin();
}

void Nursery::start(bool sim) {
  // TODO(user) - implement Nursery::start
  // throw "Not yet implemented";
}

void Nursery::setGarden(Garden* g) {
  if(g == NULL) return;
  if(garden == g) return;
  if(garden) {
    delete garden;
  }
  garden = g;
}

Garden* Nursery::getGarden() {
  return garden;
}

/**
 * @brief Get all staff members in the nursery
 * @return vector<Staff*> Vector of pointers to staff members
 */
vector<Staff*> Nursery::getStaff() {
  return staff;
}

/**
 * @brief Find a staff member by their type
 * @param type The type of staff to find
 * @return Staff* Pointer to the found staff member or NULL if not found
 */
Staff* Nursery::findStaffByType(const string& type) {
  for (Staff* s : staff) {
    if (s && s->getType().find(type) != string::npos) {
      return s;
    }
  }
  return NULL;
}

/**
 * @brief Get the current day in the nursery
 * @return int The current day
 */
int Nursery::getDay(){
  return this->day;
}

/**
 * @brief Update and advance the day in the nursery
 * @return int The new day value
 */
int Nursery::updateDay(){
  //logic to update plants etc etc.... and day pn nursery!!!
}

 /** @brief setting the chain for the customer care - stubbed
 * 
 */
void Nursery::setChain(){}
