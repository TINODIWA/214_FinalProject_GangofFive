#include <iostream>
#include "Request.h"
#include "Admin.h"
#include "Crop.h"
#include "Staff.h"

/**
 * @brief Construct a new Admin object.
 */
Admin::Admin(Staff* s) : Roles(s->getNursery(), s->getName(), s) {}

/**
 * @brief Destroy the Admin object.
 */
Admin::~Admin() {}

// staff.getjobdesc + handling sales


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


void Admin::updateInventory() {
  Nursery* med = getNursery();
  if (!med) return;
  Garden* g = med->getGarden();
  Crop* root = dynamic_cast<Crop*>(g);
  if (!root) return;
    root->removeDeadPlants();
}

void Admin::handleCustomer(Request* req) {//I dont think they handle Customers

    if (req) {
        std::cout << "Admin staff handled request: " << req->getRequest() << std::endl;
    } else if (successor) {
        successor->handleCustomer(req);
    } else {
        std::cout << "No staff could handle the request." << std::endl;
    }
}

void Admin::receive(string m, People* from, Nursery* group, string type) {
  if (!(from && group)) return;

  if (dynamic_cast<Staff*>(from)->getType() == "Manager" && group->getName() == "StaffCo_ordination") {
    if (type == "CheckInventory") {
      this->updateInventory();
    }
  }
}
