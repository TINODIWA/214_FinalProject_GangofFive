#include <iostream>
#include "Request.h"
#include "Admin.h"

/**
 * @brief Construct a new Admin object.
 */
Admin::Admin() : Roles() {

}

/**
 * @brief Destroy the Admin object.
 */
Admin::~Admin() {

}

// staff.getjobdesc + handling sales


/**
 * @brief Get the staff type for this object.
 */
std::string Admin::getType() {
	return "Admin";
}

/**
 * @brief Get the job description for this staff role.
 */
std::string Admin::jobDesc() {
	return "Admin staff responsible for administration and inventory.";
}


void Admin::updateInventory() {
    std::cout << "Admin is checking inventory records" << std::endl;
    //code
    std::cout << "Inventory updated by Admin." << std::endl;
}

void Admin::handleCustomer(Request* req) {
    if (req) {
        std::cout << "Admin staff handled request: " << req->getRequest() << std::endl;
    } else if (successor) {
        successor->handleCustomer(req);
    } else {
        std::cout << "No staff could handle the request." << std::endl;
    }
}

void Admin::handlePlant(Plant* p) {
	//doesnt handle plants here chief
}
