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
