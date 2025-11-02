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
CheckPlant::CheckPlant(Staff* s, StaffCo_ordination* m) : Command(s, m) {}

/**
 * @brief Execute the Check Plant command
 * @return void
 */
void CheckPlant::execute() {
  mediator->sendMessage("Checking plant status", appointed, "CheckPlant");
}
