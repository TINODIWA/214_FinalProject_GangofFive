#include "High.h"
#include <cstdlib>  
#include <algorithm>  

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
 * Aggressive approach - large changes, won't exceed what's needed.
 */
int High::changeAmount(int curr, int target) {
    int difference = abs(target - curr);
    return std::min(difference, 5);
}
