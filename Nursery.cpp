/**
 * @file Nursery.cpp
 * @author Unathi Tshakalisa, Nathan Chisadza
 * @brief Implementation of the Nursery class which manages the garden plot, staff, and customers as a mediator
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Nursery.h"
#include "Customer.h"
#include "Staff.h"

/**
 * @brief Construct a new Nursery object
 */
Nursery::Nursery() {}

/**
 * @brief Construct a new Nursery object with a garden plot
 * @param g Pointer to the garden plot
 */
Nursery::Nursery(GardenPlot* g) : garden(g) {}

/**
 * @brief Destroy the Nursery object
 */
Nursery::~Nursery() {}

/**
 * @brief Copy constructor for the Nursery
 * @param other The Nursery object to copy from
 */
Nursery::Nursery(const Nursery& other) {
  // vector<vector<Plant*>>::const_iterator otherPlants = (other.garden).begin();
  GardenPlot* otherGarden = other.garden;
  vector<Customer*>::const_iterator otherCustomer = (other.customers).begin();
  vector<Staff*>::const_iterator otherStaff = (other.staff).begin();
}

/**
 * @brief Start the nursery operations
 * @param sim Whether to run in simulation mode
 */
void Nursery::start(bool sim) {
  // TODO(user) - implement Nursery::start
  // throw "Not yet implemented";
}

/**
 * @brief Set the garden plot for the nursery
 * @param g Pointer to the garden plot to set
 */
void Nursery::setGarden(GardenPlot* g) {
  if (g == NULL) return;
  if (garden == g) return;
  if (garden) {
    delete garden;
  }
  garden = g;
}

/**
 * @brief Get the garden plot of the nursery
 * @return GardenPlot* Pointer to the current garden plot
 */
GardenPlot* Nursery::getGarden() {
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
