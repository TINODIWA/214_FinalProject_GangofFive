#include "Medium.h"
#include <cstdlib>  
#include <algorithm>  

Medium::Medium() : PlantCare() {

}

/**
 * @brief Copy constructor for Medium care level.
 */
Medium::Medium(const Medium& other) : PlantCare(other) {

}

Medium::~Medium() {

}

/**
 * @brief Determines the amount of change for medium care level.
 * Moderate approach - balanced changes, won't exceed what's needed.
 */
int Medium::changeAmount(int curr, int target) {
    int difference = abs(target - curr);
    return std::min(difference, 3);
}

/**
 * @brief Returns a deep copy of the current object
 */
PlantCare* Medium::clone(){
    return new Medium(*this);
}
