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
CheckInventory::CheckInventory(Staff* from, Nursery* m)
  : Command(from, m, "Please check the Inventory", "CheckInventory") {}

/**
 * @brief Execute the Check Inventory command
 * @return void
 */
void CheckInventory::execute() {
  if (!mediator) return;
  Staff* appointed = mediator->findStaffByType("BaseStaff: Admin");

  if (appointed) cout << "Admin is gonna update" << endl;
  if (appointed) mediator->sendMessage(msg, appointed, from, commandType);
}
