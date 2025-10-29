#include "Gardening.h"

void Gardening::update() {
	// TODO - implement Gardening::update
	throw "Not yet implemented";
}

string Gardening::getType() {
	// TODO - implement Gardening::getType
	throw "Not yet implemented";
}

void Gardening::checkPlants() {
	// TODO - implement Gardening::checkPlants
	throw "Not yet implemented";
}

string Gardening::handleCustomer(Request* req) {
	// TODO - implement Gardening::handleCustomer
	throw "Not yet implemented";
}

void Gardening::handlePlant(Plant* p) {
	if (p != nullptr) {
		string plantName = p->getName();
		string plantType = p->getType();
		vector<int> water = p->getWater();
		vector<int> sun = p->getSun();
		vector<int> fertiliser = p->getFertiliser();
		int attention = p->getAttention();
	}
}

Gardening::Gardening() {
	// TODO - implement Gardening::Gardening
	throw "Not yet implemented";
}

string Gardening::handleCustomer(Request* req) {
	// TODO - implement Gardening::handleCustomer
	throw "Not yet implemented";
}

void Gardening::handlePlant(Plant* p) {
	// TODO - implement Gardening::handlePlant
	throw "Not yet implemented";
}
