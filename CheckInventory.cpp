/**
 * @file CheckInventory.cpp
 * @author Nathan Chisadza
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "CheckInventory.h"

/**
 * @brief Construct a new CheckInventory object for Command
 * @param s Staff being appointed to fulfill the command
 * @param m Staff coordination pointer for the command to go to correct ConcreteMediator
 */
CheckInventory::CheckInventory(Staff *s, StaffCo_ordination *m) : Command(s, m) {}

/**
 * @brief Execute the Check Inventory command
 * @return void
 */
void CheckInventory::execute() {
  mediator->sendMessage("Checking inventory status", appointed, "CheckInventory");
}
