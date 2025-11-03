/**
 * @file High.cpp
 * @author Dominique Nigatu
 * @brief Implementation of the High care level class which represents plants requiring intensive care and maintenance with maximum growth rate
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "High.h"

/**
 * @brief Construct a new High care level object
 */
High::High() : PlantCare() {

}

/**
 * @brief Copy constructor for High care level
 * @param other The High care level object to copy from
 */
High::High(const High& other) : PlantCare(other) {

}

/**
 * @brief Destroy the High care level object
 */
High::~High() {

}

/**
 * @brief Calculate the change amount for high care level plants
 * @param currWL Current water level
 * @param WL Target water level
 * @return int Always returns 3, representing maximum growth rate
 */
int High::changeAmount(int currWL, int WL) {
    (void)currWL;  // Mark as intentionally unused
    (void)WL;      // Mark as intentionally unused
    return 3;
}

/**
 * @brief Returns a deep copy of the current object
 * @return PlantCare* Pointer to a new High care level object
 */
PlantCare* High::clone(){
    return new High(*this);
}
