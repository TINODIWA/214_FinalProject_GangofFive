/**
 * @file Low.cpp
 * @author Dominique Nigatu
 * @brief Implementation of the Low care level class which represents plants requiring minimal care and maintenance with base growth rate
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Low.h"

/**
 * @brief Construct a new Low care level object
 */
Low::Low() : PlantCare() {
    
}

/**
 * @brief Copy constructor for Low care level
 * @param other The Low care level object to copy from
 */
Low::Low(const Low& other) : PlantCare(other) {

}

/**
 * @brief Destroy the Low care level object
 */
Low::~Low() {

}

/**
 * @brief Determines the amount of change for low care level.
 */
int Low::changeAmount(int currWL, int WL) {
     (void)WL;
     int base = 1;
     int delta = base;
     if (delta < 0) delta = 0;
     return delta;
}

/**
 * @brief Returns a deep copy of the current object
 */
PlantCare* Low::clone(){
    return new Low(*this);
}
