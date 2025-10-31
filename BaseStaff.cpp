#include "BaseStaff.h"

BaseStaff::BaseStaff() : Staff() {
}


std::string BaseStaff::jobDesc() {
    return "Base staff member responsible for general duties.";
}

void BaseStaff::handleCustomer(Request* req) {
	if (req) {
		std::cout << "BaseStaff handled request: " << req->getRequest() << std::endl;
	} else {
		std::cout << "BaseStaff received an invalid request." << std::endl;
	}
}

void BaseStaff::handlePlant(Plant* p) {
	//??????
}

std::string BaseStaff::getType() {
    return "BaseStaff";
}
