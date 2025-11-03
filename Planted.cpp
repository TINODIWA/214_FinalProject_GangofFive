/**
 * @file Planted.cpp
 * @author Gang of Five
 * @brief Implementation of the Planted state class for the Plant State pattern
 * @version 1.0
 * @date 2025-10-11
 *
 * @copyright Copyright (c) 2025
 */

#include "Planted.h"
#include "Plant.h"
#include "Growing.h"
#include "Dying.h"

/**
 * @brief Default constructor for the Planted state
 */
Planted::Planted() {}

/**
 * @brief Default destructor for the Planted state
 */
Planted::~Planted() {}

/**
 * @brief Copy constructor for the Planted state
 * @param other Reference to another PlantState object to copy from
 */
Planted::Planted(const PlantState& other) : PlantState(other) {}

/**
 * @brief Handles the state transition from Planted to the next state
 */
void Planted::handleChange(Plant* p) {
  PlantState* curr = p->currState();
  if (dying(p)) {
    PlantState* dying = new Dying();
    dying->setPrev(curr);
    p->setState(dying);
    return;
  }

  vector<int> days = p->getDays();

  if (days[0] == days[1]) {
    delete curr;
    p->setState(new Growing());
  }
}

/**
 * @brief Returns the string representation of the current state
 * @return string The name of the current state ("Planted")
 */
string Planted::getState() {
  return "Planted";
}

/**
 * @brief clones the state of the plant
 *
 */
PlantState* Planted::clone() {
  return new Planted(*this);
}
