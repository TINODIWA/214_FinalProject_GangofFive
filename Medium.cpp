/**
 * @file Medium.cpp
 * @author Dominique Nigatu
 * @brief Implementation of the Medium care level class which represents plants requiring moderate care and maintenance with standard growth rate
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Medium.h"

/**
 * @brief Construct a new Medium care level object
 */
Medium::Medium() : PlantCare() {

}

/**
 * @brief Copy constructor for Medium care level
 * @param other The Medium care level object to copy from
 */
Medium::Medium(const Medium& other) : PlantCare(other) {

}

/**
 * @brief Destroy the Medium care level object
 */
Medium::~Medium() {

}

/**
 * @brief Determines the amount of change for medium care level
 * @param currWL Current water level (unused)
 * @param WL Target water level (unused)
 * @return int Returns 2, representing moderate growth rate
 */
int Medium::changeAmount(int currWL, int WL) {
    (void)currWL;
    (void)WL;
    return 2;
}

/**
 * @brief Returns a deep copy of the current object
 * @return PlantCare* Pointer to a new Medium care level object
 */
PlantCare* Medium::clone(){
    return new Medium(*this);
}
