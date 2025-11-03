/**
 * @file FireStaff.cpp
 */

#include "FireStaff.h"
#include "Nursery.h"
#include <iostream>

FireStaff::FireStaff(Staff* manager, Nursery* m, Staff* f, const std::string& message)
  : Command(manager, m, message, "FireStaff"), firee(f) {}

FireStaff::~FireStaff() {
  firee = NULL;
}

void FireStaff::execute() {
  if (!mediator || !firee) {
    std::cout << "[FireStaff] Missing mediator or firee" << std::endl;
    return;
  }
  mediator->removeStaff(firee);
  std::cout << (from ? from->getName() : std::string("<unknown>"))
            << " fired " << firee->getName() << std::endl;
}
