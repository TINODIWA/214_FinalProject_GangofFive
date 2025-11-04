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

/**
 * @brief Default constructor for the Planted state
 */
Planted::Planted() {
    // Constructor implementation
}

/**
 * @brief Default destructor for the Planted state
 */
Planted::~Planted(){}

/**
 * @brief Copy constructor for the Planted state
 * @param other Reference to another PlantState object to copy from
 */
Planted::Planted(const PlantState& other) : PlantState(other) {
    // Copy constructor implementation
}

/**
 * @brief Handles the state transition from Planted to the next state
 */
void Planted::handleChange() {
    // State transition logic implementation
}

/**
 * @brief Creates a deep copy of the current Planted state
 * @return PlantState* Pointer to a new Planted state object
 */
PlantState* Planted::clone() {
    return new Planted(*this);
}

/**
 * @brief Returns the string representation of the current state
 * @return string The name of the current state ("Planted")
 */
string Planted::getState() {
    return "Planted";
}
