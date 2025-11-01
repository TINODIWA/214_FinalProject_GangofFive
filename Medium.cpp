#include "Medium.h"

Medium::Medium() : PlantCare() {

}

Medium::Medium(const Medium& other) : PlantCare(other) {

}

Medium::~Medium() {

}

int Medium::changeAmount() {
    return 2;
}
