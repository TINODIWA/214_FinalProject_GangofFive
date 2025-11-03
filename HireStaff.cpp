/**
 * @file HireStaff.cpp
 */

#include "HireStaff.h"
#include "Nursery.h"
#include <iostream>

HireStaff::HireStaff(Staff* manager, Nursery* m, Staff* h, const std::string& message)
  : Command(manager, m, message, "HireStaff"), hiree(h) {}

HireStaff::~HireStaff() {
  hiree = NULL;
}

void HireStaff::execute() {
  if (!mediator || !hiree) {
    std::cout << "[HireStaff] Missing mediator or hiree" << std::endl;
    return;
  }
  mediator->addStaff(hiree);
  std::cout << (from ? from->getName() : std::string("<unknown>"))
            << " hired " << hiree->getName() << std::endl;
}
