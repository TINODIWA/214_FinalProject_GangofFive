#include "Medium.h"

Medium::Medium() : PlantCare() {

}

Medium::Medium(const Medium& other) : PlantCare(other) {

}

Medium::~Medium() {

}

int Medium::changeAmount(int currWL, int WL) {
    (void)currWL;
    (void)WL;
    return 2;
}
