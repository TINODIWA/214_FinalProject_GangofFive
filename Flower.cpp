#include "Flower.h"

Flower::Flower() : Plant() {
}

Flower::Flower(const Plant& other) : Plant(other) {
}

Flower::~Flower() {
}

Plant* Flower::clone() {
	return new Flower(*this);
}
