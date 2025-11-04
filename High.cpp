#include "High.h"

High::High() : PlantCare() {

}

/**
 * @brief Copy constructor for High care level.
 */
High::High(const High& other) : PlantCare(other) {

}

High::~High() {

}


/**
 * @brief Determines the amount of change for high care level.
 */
int High::changeAmount(int currWL, int WL) {
    (void)currWL;  // Mark as intentionally unused
    (void)WL;      // Mark as intentionally unused
    return 3;
}

/**
 * @brief Returns a deep copy of the current object
 */
PlantCare* High::clone(){
    return new High(*this);
}
