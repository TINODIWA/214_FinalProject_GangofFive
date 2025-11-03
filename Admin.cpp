/**
 * @file Admin.cpp
 * @author Nathan Chisadza, Unathi Tshakalisa
 * @brief Defines implementation for Admin staff
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>
#include "Request.h"
#include "Admin.h"
#include "Crop.h"
#include "Staff.h"
#include "CustomerCare.h"

/**
 * @brief Construct a new Admin object
 * @param s The staff member to be decorated with admin role
 */
Admin::Admin(Staff* s) : Roles(s->getNursery(), s->getName(), s) {}

/**
 * @brief Destroy the Admin object.
 */
Admin::~Admin() {}


/**
 * @brief Get the staff type for this object.
 */
std::string Admin::getType() {
	return Roles::getType() + ": Admin";
}

/**
 * @brief Get the job description for this staff role.
 */
std::string Admin::jobDesc() {
	return Roles::jobDesc() + "\nAdmin staff responsible for administration and inventory.";
}


/**
 * @brief Update the inventory by removing dead plants
 */
void Admin::updateInventory() {
//   Nursery* med = getNursery();
//   if (!med) return;
//   GardenPlot* g = med->getGarden();
//   Crop* root = dynamic_cast<Crop*>(g);
//   if (!root) return;
//     root->removeDeadPlants();
}

/**
 * @brief Handle a customer request
 * @param req The request to handle
 * @param customer The customer making the request
 */
void Admin::handleCustomer(Request req, Customer* customer) {//stubbed

}

/**
 * @brief Receive a message from another staff member or group
 * @param m The message content
 * @param from The sender of the message
 * @param group The nursery group involved
 * @param type The type of message
 */
void Admin::receive(string m, People* from, Nursery* group, string type) {
  if (!(from && group)) return;

  if (dynamic_cast<Staff*>(from)->getType() == "Manager" && group->getName() == "StaffCo_ordination") {
    if (type == "CheckInventory") {
      this->updateInventory();
    }
  }
}

/**
 * @brief Update the admin's state based on plant changes-stubbed
 * @param p The plant that triggered the update
 */
void Admin::update(Plant *p){}

/**
 * @brief Handle plant-related tasks-stubbed
 * @param p The plant to handle
 */
void Admin::handlePlant(Plant *p){}
