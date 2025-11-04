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

/**
 * @brief Default constructor for the Growing state
 */
Growing::Growing() {
    // Constructor implementation
}

/**
 * @brief Default destructor for the Growing state
 */
Growing::~Growing(){}

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
void Growing::handleChange() {
    // State transition logic implementation
}

/**
 * @brief Creates a deep copy of the current Growing state
 * @return PlantState* Pointer to a new Growing state object
 */
PlantState* Growing::clone() {
    return new Growing(*this);
}

/**
 * @brief Returns the string representation of the current state
 * @return string The name of the current state ("Growing")
 */
string Growing::getState() {
    return "Growing";
}
