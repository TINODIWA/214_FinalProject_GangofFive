#include "Low.h"

Low::Low() : PlantCare() {}

Low::Low(const Low& other) : PlantCare(other) {
    
}

Low::~Low() {

}

int Low::changeAmount() {
     return 1; 
}
