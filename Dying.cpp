/**
 * @file Dying.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Dying.h"
#include "Plant.h"
#include "Dead.h"

/**
 * @brief Default constructor for the Dying state
 */
Dying::Dying() : prev(nullptr) {
  // Constructor implementation
}

/**
 * @brief Default destructor for the Dying state
 */
Dying::~Dying() {}

/**
 * @brief Copy constructor for the Dying state
 * @param other Reference to another PlantState object to copy from
 */
Dying::Dying(const PlantState& other) : PlantState(other) {
  // Copy constructor implementation
}

/**
 * @brief Handles the state transition from Dying to the next state
 */
void Dying::handleChange(Plant* p) {
  PlantState* curr = p->currState();

  string state = prev->getState();
  if (state == "Mature") {
    delete curr;
    p->setState(new Dead());
  } else if (!dying(p)) {
    delete curr;
    p->setState(prev);
  }
}

/**
 * @brief Returns the string representation of the current state
 * @return string The name of the current state ("Dying")
 */
string Dying::getState() {
  return "Dying";
}

/**
 * @brief sets the prev attribute
 *
 */
void Dying::setPrev(PlantState* prev) {
  this->prev = prev;
}

/**
 * @brief clones the state of the plant
 *
 */
PlantState* Dying::clone() {
  return new Dying(*this);
}
