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
Management::Management(Staff* s) : Roles(s->getNursery(), s->getName(), s) {}

/**
 * @brief Destroy the Management object.
 */
Management::~Management() {}

/**
 * @brief Get the staff type for this object.
 */
std::string Management::getType() {
	return Roles::getType() + ": Management";
}

/**
 * @brief Get the job description for this staff role.
 */
std::string Management::jobDesc() {
	return Roles::jobDesc() + "\nManagement staff responsible for assigning tasks and operations.";
}


void Management::assignTasks() {
    
}

void Management::addCommand(Command* c) {
    if (c) {
        cmd.push_back(c);
    }
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

// void Management::receive(string m, People* from, Nursery* group, string type) {
//     if (!group) return;

//     if (type == "CheckPlant" || type == "PlantDeadReport") {
//         std::cout << "Management received plant report: " << m << std::endl;
//         group->sendMessage(string("Please update inventory to remove dead plants"), this, string("UpdateInventory"));
//     }
// }

void Management::receive(string m, People* from, Nursery* group, string type) {
}

