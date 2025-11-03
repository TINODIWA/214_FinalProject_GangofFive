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
#include "CustomerCare.h"
#include "Customer.h"

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

void Management::assignTasks(Nursery* group) {
  CheckInventory cmd1(this, group);
  cmd1.execute();
  CheckPlant cmd2(this, group);
  cmd2.execute();
}

void Management::hireStaff(Staff* newStaff) {
  Nursery* med = getNursery();
  if (!med || !newStaff) return;

  HireStaff cmd(this, med, newStaff);
  cmd.execute();
}

void Management::fireStaff(Staff* exStaff) {
  Nursery* med = getNursery();
  if (!med || !exStaff) return;

  FireStaff cmd(this, med, exStaff);
  cmd.execute();
}

void Management::handleCustomer(Request req, Customer* customer) {  // add complaints
  if (req.getRequest() == "Complaint") {
    std::cout << "\nI am " + name + " and I will be assisting you today.\nPlease enter your complaint below:"
              << std::endl;

    string complaint;
    cin >> complaint;
    nursery->complaints.push_back(complaint);
    std::cout << "\nI'm so sorry this was your experience.At GoF Nursery we value our customers feed back and so your "
                 "complaint has been added to our complaints log for improvement. \nRecent complaints:"
              << endl;
    for (string c : nursery->complaints) {
      cout << c << "\n" << endl;
    }
    std::cout << " \nPlease visit soon for a better "
                 "experience!"
              << endl;

  } else if (successor) {
    successor->handleCustomer(req, customer);
  } else {
    std::cout << "No staff could handle the request." << std::endl;
  }
}

void Management::receive(string m, People* from, Nursery* group, string type) {
  std::cout << getName() << " (" << getType() << ") received [" << type << "]: " << m;
  if (from) std::cout << " from " << from->getName() << " (" << static_cast<Staff*>(from)->getType() << ")";
  std::cout << std::endl;

  if (type == "PlantDeadReport") {
    CheckInventory cmd(this, group);
    cmd.execute();
  } else {
    cout << "Sorry, " << this->getName() << " (" << this->getType() << ") can not help with this request" << endl;
  }
}

void Management::update(Plant* p) {}       // stubbed
void Management::handlePlant(Plant* p) {}  // stubbed