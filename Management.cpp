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



Management::Management() : Roles(), cmd(nullptr) {

}

Management::~Management() {

}

std::string Management::getType() {
	return "Management";
}

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

