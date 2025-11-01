#include "High.h"

High::High() : PlantCare() {

}

High::High(const High& other) : PlantCare(other) {

}

High::~High() {

}

int High::changeAmount(int currWL, int WL) {
    (void)currWL;  // Mark as intentionally unused
    (void)WL;      // Mark as intentionally unused
    return 3;
}
