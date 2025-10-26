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
void CheckInventory::execute()
{
	mediator->sendMessage("Checking inventory status", appointed, "CheckInventory");
}