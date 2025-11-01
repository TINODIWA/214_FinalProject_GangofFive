/**
 * @file Management.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Management.h"


/**
 * @brief Construct a new Management object.
 */
Management::Management() : Roles(), cmd(nullptr) {

}

/**
 * @brief Destroy the Management object.
 */
Management::~Management() {

}

/**
 * @brief Get the staff type for this object.
 */
std::string Management::getType() {
	return "Management";
}

/**
 * @brief Get the job description for this staff role.
 */
std::string Management::jobDesc() {
	return "Management staff responsible for assigning tasks and operations.";
}


void Management::assignTasks() {
    std::cout << "Management is reviewing staff workload..." << std::endl;
    //code
    std::cout << "Tasks assigned by Management." << std::endl;
}

void Management::handleCustomer(Request* req) {
    if (req) {
        std::cout << "Management staff handled request: " << req->getRequest() << std::endl;
    } else if (successor) {
        successor->handleCustomer(req);
    } else {
        std::cout << "No staff could handle the request." << std::endl;
    }
}

void Management::handlePlant(Plant* p) {
    //doesnt handle plants boss
}

