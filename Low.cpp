#include "Low.h"

Low::Low() : PlantCare() {
    
}

Low::Low(const Low& other) : PlantCare(other) {

}

Low::~Low() {

}

int Low::changeAmount(int currWL, int WL) {
     (void)WL;
     int base = 1;
     int delta = base;
     if (delta < 0) delta = 0;
     return delta;
}
