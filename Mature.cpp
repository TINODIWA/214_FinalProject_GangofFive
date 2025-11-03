/**
 * @file Mature.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Mature.h"
#include "Plant.h"
#include "Dying.h"

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
  
}

/**
 * @brief Returns the string representation of the current state
 * @return string The name of the current state ("Mature")
 */
string Mature::getState() {
  return "Mature";
}
