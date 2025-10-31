/**
 * @file Nursery.cpp
 * @author Unathi Tshakalisa, Nathan Chisadza
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


Nursery::Nursery() : staffCount(0), garden(new Garden()) {}
}

Nursery::~Nursery() {}
Nursery::Nursery(const Nursery& other) {
  // helper lambda to extract raw Plant* whether clone() returns Plant* or std::unique_ptr<Plant>
  auto get_raw = [](auto p) -> Plant* {
    using T = decltype(p);
    if constexpr (std::is_pointer_v<T>) {
      return p;
    } else {
      return p.release();
    }
  };

  // copy plant rows and clone each Plant
  for (const auto& row : other.plants) {
    vector<Plant*> temp;
    for (const Plant* plantPtr : row) {
      auto cloneResult = plantPtr->clone(); // may be Plant* or std::unique_ptr<Plant>
      temp.push_back(get_raw(std::move(cloneResult)));
    }
    plants.push_back(temp);
  }

  // copy customers
  for (const auto& c : other.customers) {
    customers.push_back(new Customer(*c));
  }

  // copy staff
  for (const auto& s : other.staff) {
    staff.push_back(new Staff(*s));
  }
}
// removed stray closing brace

void Nursery::addPlant(Plant* p) {
  // TODO(user) - implement Nursery::addPlant
  // throw "Not yet implemented";
}

void Nursery::removePlant(Plant* p) {
  // TODO(user) - implement Nursery::removePlant
  // throw "Not yet implemented";
}

void Nursery::start(bool sim) {
  // TODO(user) - implement Nursery::start
  // throw "Not yet implemented";
}

void Nursery::addStaff(Staff* s) {
  staff.push_back(s);
}

void Nursery::removeStaff(Staff* s) {

}

void Nursery::notify() {
  // TODO(user) - implement Nursery::notify
  // throw "Not yet implemented";
}
