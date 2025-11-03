/**
 * @file Growing.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Growing.h"
#include "Plant.h"
#include "Dying.h"
#include "Mature.h"

/**
 * @brief Default constructor for the Growing state
 */
Growing::Growing() {
  // Constructor implementation
}

/**
 * @brief Default destructor for the Growing state
 */
Growing::~Growing() {}

/**
 * @brief Copy constructor for the Growing state
 * @param other Reference to another PlantState object to copy from
 */
Growing::Growing(const PlantState& other) : PlantState(other) {
  // Copy constructor implementation
}

/**
 * @brief Handles the state transition from Growing to the next state
 */
void Growing::handleChange(Plant* p) {
  PlantState* curr = p->currState();
  if (dying(p)) {
    p->setState(new Dying());
    p->currState()->setPrev(curr);
    return;
  }

  vector<int> days = p->getDays();
  if (days[0] == days[2]) {
    delete curr;
    p->setState(new Mature());
  }
}

/**
 * @brief Returns the string representation of the current state
 * @return string The name of the current state ("Growing")
 */
string Growing::getState() {
  return "Growing";
}

/**
 * @brief clones the state of the plant
 *
 */
PlantState* Growing::clone() {
  return new Growing(*this);
}
