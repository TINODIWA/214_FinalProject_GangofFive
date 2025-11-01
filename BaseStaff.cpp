#include "BaseStaff.h"

/**
 * @brief Construct a new BaseStaff object.
 */
BaseStaff::BaseStaff() : Staff() {
}

/**
 * @brief Get the job description for this staff role.
 */
std::string BaseStaff::jobDesc() {
    return "Base staff member responsible for general duties.";
}

/**
 * @brief Get the staff type for this object.
 */
std::string BaseStaff::getType() {
	return "BaseStaff";
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

