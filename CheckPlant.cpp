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
CheckPlant::CheckPlant(Staff* s, StaffCo_ordination* m) : Command(s, m, "Checking plant status", "CheckPlant") {}

/**
 * @brief Execute the Check Plant command
 * Sends the command only to Gardening staff through the mediator
 * @return void
 */
void CheckPlant::execute() {
  if (!mediator || !appointed) {
    return;
  }
  
  // Check if the appointed staff is a Gardening staff member
  if (appointed->getType().find("Gardening") != string::npos) {
    // Cast to StaffCo_ordination to use the correct sendMessage signature
    StaffCo_ordination* coordinator = dynamic_cast<StaffCo_ordination*>(mediator);
    if (coordinator) {
      coordinator->sendMessage("Checking plant status", appointed, from, "CheckPlant");
    }
  } else {
    cout << "CheckPlant command can only be assigned to Gardening staff!" << endl;
  }
}
