#include "Shrub.h"

Shrub::Shrub() : Plant() {
}

Shrub::Shrub(const Plant& other) : Plant(other) {
}

Shrub::~Shrub() {
}

Plant* Shrub::clone() {
	return new Shrub(*this);
}
