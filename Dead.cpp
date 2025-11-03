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
#include "Plant.h"

/**
 * @brief Default constructor for the Dead state
 */
Dead::Dead() {
    // Constructor implementation
}

/**
 * @brief Default destructor for the Dead state
 */
Dead::~Dead(){}

/**
 * @brief Copy constructor for the Dead state
 * @param other Reference to another PlantState object to copy from
 */
Dead::Dead(const PlantState& other) : PlantState(other) {
    // Copy constructor implementation
}

/**
 * @brief Handles the state transition from Dead to the next state
 */
void Dead::handleChange(Plant* p) {
    cout<<"This Plant is dead :(\n";
}


/**
 * @brief Returns the string representation of the current state
 * @return string The name of the current state ("Dead")
 */
string Dead::getState() {
    return "Dead";
}
