#include "PlantCare.h"

PlantCare::PlantCare(const PlantCare& other){}

int PlantCare::waterAlgorithm() {
	// TODO - implement PlantCare::waterAlgorithm
	//throw "Not yet implemented";
}

int PlantCare::sunAlgorithm() {
	// TODO - implement PlantCare::sunAlgorithm
	//throw "Not yet implemented";
}

int PlantCare::fertiliseAlgorithm() {
	// TODO - implement PlantCare::fertiliseAlgorithm
	//throw "Not yet implemented";
}

PlantCare::PlantCare() {
	// TODO - implement PlantCare::PlantCare
	//throw "Not yet implemented";
}

/**
 * @brief Calculate new resource level based on current, required and change amount
 * @param current Current level of the resource
 * @param required Required level of the resource
 * @param change Amount of change to apply
 * @return New level after applying change, never exceeding required level
 */
int PlantCare::changeAmount(int current, int required, int change)
{
    if (current >= required) 
	return current;
    if (change <= 0) 
	return current;
    int newVal = current + change;
    if (newVal > required) newVal = required;
    return newVal;
}
