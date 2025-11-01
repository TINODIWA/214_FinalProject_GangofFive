#include "Medium.h"

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
 */
int Medium::changeAmount(int currWL, int WL) {
    (void)currWL;
    (void)WL;
    return 2;
}
