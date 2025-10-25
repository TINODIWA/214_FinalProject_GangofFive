#include "Crop.h"

/**
 * @brief Construct a new Crop:: Crop object
 * 
 */
Crop::Crop(): Plant(){}

void Crop::addPlant(Plant* p) {
	plants.push_back(p);
}

Plant* Crop::clone() {
	// TODO - implement Crop::clone
	throw "Not yet implemented";
}
