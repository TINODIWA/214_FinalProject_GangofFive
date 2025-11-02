/**
 * @file CheckPlant.cpp
 * @author Nathan Chisadza
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "CheckPlant.h"

/**
 * @brief Construct a new CheckPlant object for Command
 * @param s Staff being appointed to fulfill the command
 * @param m Staff coordination pointer for the command to go to correct ConcreteMediator
 */
CheckPlant::CheckPlant(Staff* s, Nursery* m) : Command(s, m, "Please check up on the plants", "CheckPlant") {}

/**
 * @brief Execute the Check Plant command
 * Sends the command only to Gardening staff through the mediator
 * @return void
 */
void CheckPlant::execute() {
  if (!mediator) return;
  Staff* appointed = NULL;
  vector<Staff*> staffList = mediator->getStaff();
  for (Staff* s : staffList) {
    if (s->getType() == "Gardening") {
      appointed = s;
      break;
    }
  }

  if (appointed) mediator->sendMessage(msg, appointed, from, commandType);
  delete appointed;
}
