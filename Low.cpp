#include "Low.h"
#include <cstdlib>  //for abs
#include <algorithm>  //for min

Low::Low() : PlantCare() {
    
}

/**
 * @brief Copy constructor for Low care level.
 */
Low::Low(const Low& other) : PlantCare(other) {

}

Low::~Low() {

}

/**
 * @brief Determines the amount of change for low care level.
 * Conservative approach - small changes, won't exceed what's needed.
 */
int Low::changeAmount(int curr, int target) {
    int difference = abs(target - curr);
    return std::min(difference, 1);
}

/**
 * @brief Returns a deep copy of the current object
 */
PlantCare* Low::clone(){
    return new Low(*this);
}
