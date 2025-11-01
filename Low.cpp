#include "Low.h"

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
 */
int Low::changeAmount(int currWL, int WL) {
     (void)WL;
     int base = 1;
     int delta = base;
     if (delta < 0) delta = 0;
     return delta;
}
