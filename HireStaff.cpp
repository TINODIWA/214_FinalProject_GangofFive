/**
 * @file HireStaff.cpp
 * @author Nathan Chisadza
 * @brief Implementation of the HireStaff command class which handles the hiring of new staff members in the nursery
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "HireStaff.h"
#include "Nursery.h"
#include <iostream>

/**
 * @brief Construct a new Hire Staff command
 * @param manager The staff member initiating the hire
 * @param m The nursery mediator
 * @param h The staff member being hired
 * @param message The message associated with the hire command
 */
HireStaff::HireStaff(Staff* manager, Nursery* m, Staff* h, const std::string& message)
    : Command(manager, m, message, "HireStaff"), hiree(h) {}

/**
 * @brief Destroy the Hire Staff command
 */
HireStaff::~HireStaff() {
  hiree = NULL;
}

/**
 * @brief Execute the hire staff command
 */
void HireStaff::execute() {
  if (!mediator || !hiree) {
    std::cout << "[HireStaff] Missing mediator or hiree" << std::endl;
    return;
  }
  mediator->addStaff(hiree);
  std::cout << (from ? from->getName() : std::string("<unknown>")) << " hired " << hiree->getName() << std::endl;
}
