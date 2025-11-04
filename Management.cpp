/**
 * @file Management.cpp
 * @author Unathi Tshakalisa, Nathan Chisadza, Dominique Nigatu
 * @brief Implementation of the Management class which handles staff supervision, task assignment, and customer complaint resolution
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

/**
 * @brief Assign check inventory and plant inspection tasks
 * @param group The nursery group to assign tasks for
 */
void Management::assignTasks(Nursery* group) {
  CheckInventory cmd1(this, group);
  cmd1.execute();
  CheckPlant cmd2(this, group);
  cmd2.execute();
}

/**
 * @brief Hire a new staff member
 * @param newStaff The staff member to hire
 */
void Management::hireStaff(Staff* newStaff) {
  Nursery* med = getNursery();
  if (!med || !newStaff) return;

  HireStaff cmd(this, med, newStaff);
  cmd.execute();
}

/**
 * @brief Fire an existing staff member
 * @param exStaff The staff member to fire
 */
void Management::fireStaff(Staff* exStaff) {
  Nursery* med = getNursery();
  if (!med || !exStaff) return;

  FireStaff cmd(this, med, exStaff);
  cmd.execute();
}

/**
 * @brief Handle customer requests, particularly complaints
 * @param req The customer request to handle
 * @param customer The customer making the request
 */
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

/**
 * @brief Receive and handle messages from other staff members
 * @param m The message content
 * @param from The sender of the message
 * @param group The nursery group context
 * @param type The type of message
 */
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

/**
 * @brief Update method for plant state changes
 * @param p The plant that has been updated
 */
void Management::update(Plant* p) {}       // stubbed

/**
 * @brief Handle plant-related tasks
 * @param p The plant to handle
 */
void Management::handlePlant(Plant* p) {}  // stubbed