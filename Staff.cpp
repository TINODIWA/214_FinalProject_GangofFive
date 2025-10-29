#include "Staff.h"

void Staff::handlePlant(Plant* p) {}

void Staff::handleCustomer(Request* req) {
	// TODO - implement Staff::handleCustomer
	//throw "Not yet implemented";
}

Staff::Staff(): People() {}

Staff::~Staff() {}

Staff::Staff(const Staff& other): People(other) {
	this->name = other.name;
	this->level = other.level;
	this->responsibilities = other.responsibilities;
	this->successor = other.successor;
}

string Staff::jobDesc() {
	// TODO - implement Staff::JobDesc
	//throw "Not yet implemented";	
}

string Staff::getType() {
	// TODO - implement Staff::getType
	//throw "Not yet implemented";
}
