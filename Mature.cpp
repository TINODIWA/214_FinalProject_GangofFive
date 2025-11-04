/**
 * @file Mature.cpp
 * @author Swelihle Makhathini
 * @brief Implementation of the Mature state class which represents a fully grown plant that can either maintain its state or transition to dying/dead states
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Mature.h"
#include "Plant.h"
#include "Dying.h"
#include "Dead.h"

/**
 * @brief Default constructor for the Mature state
 */
Mature::Mature() {
  // Constructor implementation
}

/**
 * @brief Default destructor for the Mature state
 */
Mature::~Mature() {}

/**
 * @brief Copy constructor for the Mature state
 * @param other Reference to another PlantState object to copy from
 */
Mature::Mature(const PlantState& other) : PlantState(other) {
  // Copy constructor implementation
}

/**
 * @brief Handles the state transition from Mature to the next state
 */
void Mature::handleChange(Plant* p) {
  PlantState* curr = p->currState();
  if (dying(p)) {
    p->setState(new Dying());
    p->currState()->setPrev(curr);
    return;
  }

  vector<int> days = p->getDays();
  if (days[0] == days[3]) {
    delete curr;
    p->setState(new Dead());
  }
}

/**
 * @brief Returns the string representation of the current state
 * @return string The name of the current state ("Mature")
 */
string Mature::getState() {
  return "Mature";
}

/**
 * @brief clones the state of the plant
 *
 */
PlantState* Mature::clone() {
  return new Mature(*this);
}
