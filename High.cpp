#include "High.h"

High::High() : PlantCare() {

}

High::High(const High& other) : PlantCare(other) {

}

High::~High() {

}

int High::changeAmount() {
    return 3;
}
