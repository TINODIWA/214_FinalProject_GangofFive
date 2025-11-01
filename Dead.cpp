/**
 * @file Dead.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Dead.h"
/**
 * @brief Default constructor for the Dead state
 * @details Initializes a new Dead state object, representing the initial state
 *          of a plant after it has been planted in soil
 */
Dead::Dead() {
    // Constructor implementation
}

/**
 * @brief Copy constructor for the Dead state
 * @param other Reference to another PlantState object to copy from
 * @details Creates a new Dead state by copying the attributes from another PlantState
 */
Dead::Dead(const PlantState& other) : PlantState(other) {
    // Copy constructor implementation
}

/**
 * @brief Handles the state transition from Dead to the next state
 * @details This method is called when conditions are met for the plant to
 *          transition from the Dead state to the next growth state
 */
void Dead::handleChange() {
    // State transition logic implementation
}

/**
 * @brief Creates a deep copy of the current Dead state
 * @return PlantState* Pointer to a new Dead state object
 * @details Part of the prototype pattern implementation, allows for creating
 *          new instances of the Dead state
 */
PlantState* Dead::clone() {
    return new Dead(*this);
}

/**
 * @brief Returns the string representation of the current state
 * @return string The name of the current state ("Dead")
 * @details Used for state identification and debugging purposes
 */
string Dead::getState() {
    return "Dead";
}
