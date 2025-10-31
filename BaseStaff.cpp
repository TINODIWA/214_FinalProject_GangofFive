/**
 * @file BaseStaff.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

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
