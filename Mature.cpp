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
/**
 * @brief Default constructor for the Mature state
 * @details Initializes a new Mature state object, representing the initial state
 *          of a plant after it has been planted in soil
 */
Mature::Mature() {
    // Constructor implementation
}

/**
 * @brief Copy constructor for the Mature state
 * @param other Reference to another PlantState object to copy from
 * @details Creates a new Mature state by copying the attributes from another PlantState
 */
Mature::Mature(const PlantState& other) : PlantState(other) {
    // Copy constructor implementation
}

/**
 * @brief Handles the state transition from Mature to the next state
 * @details This method is called when conditions are met for the plant to
 *          transition from the Mature state to the next growth state
 */
void Mature::handleChange() {
    // State transition logic implementation
}

/**
 * @brief Creates a deep copy of the current Mature state
 * @return PlantState* Pointer to a new Mature state object
 * @details Part of the prototype pattern implementation, allows for creating
 *          new instances of the Mature state
 */
PlantState* Mature::clone() {
    return new Mature(*this);
}

/**
 * @brief Returns the string representation of the current state
 * @return string The name of the current state ("Mature")
 * @details Used for state identification and debugging purposes
 */
string Mature::getState() {
    return "Mature";
}
