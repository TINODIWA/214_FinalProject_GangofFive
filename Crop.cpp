#include "Crop.h"

/**
 * @brief Construct a new Crop:: Crop object
 * 
 */
Crop::Crop(): Plant(){}

/**
 * @brief Destructor that deletes all plants in vector
 * 
 * Iterates through the plants vector, deleting each Plant pointer
 * to prevent memory leaks
 */
Crop::~Crop() {
	for (Plant* p : plants) {
        delete p;
    }
    plants.clear();
}

/**
 * @brief Copy constructor that performs a deep copy of the Crop
 * 
 * @param other The Crop object to copy from
 * 
 * Creates a new Crop with its own copy of each Plant in the vector.
 * Each Plant is cloned to create a completely independent copy.
 */
Crop::Crop(const Crop &other): Plant(other) {
	for (Plant* p : other.plants) {
		if (p != NULL)
		{
			plants.push_back(p->clone());
		}
	}
}

/**
 * @brief Construct a new Crop:: Crop object with a name
 */
Crop::Crop(std::string name) : Plant() {
	setName(name);
}

void Crop::addPlant(Plant* p) {
	plants.push_back(p);
}

/**
 * @brief Create a copy of this Crop.
 * @return Pointer to a new Crop.
 */
Plant* Crop::clone() {
	return new Crop(*this);
}
