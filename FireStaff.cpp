/**
 * @file FireStaff.cpp
 * @author Nathan Chisadza
 * @brief Implementation of the FireStaff command class, which handles staff termination using the Command pattern
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "FireStaff.h"
#include "Nursery.h"
#include <iostream>

/**
 * @brief Construct a new FireStaff command
 * @param manager Pointer to the staff member initiating the firing
 * @param m Pointer to the nursery mediator
 * @param f Pointer to the staff member being fired
 * @param message The termination message
 */
FireStaff::FireStaff(Staff* manager, Nursery* m, Staff* f, const std::string& message)
    : Command(manager, m, message, "FireStaff"), firee(f) {}

/**
 * @brief Destroy the FireStaff command
 */
FireStaff::~FireStaff() {
  firee = NULL;
}

/**
 * @brief Execute the firing command
 */
void FireStaff::execute() {
  if (!mediator || !firee) {
    std::cout << "[FireStaff] Missing mediator or firee" << std::endl;
    return;
  }
  mediator->removeStaff(firee);
  std::cout << (from ? from->getName() : std::string("<unknown>")) << " fired " << firee->getName() << std::endl;
}
