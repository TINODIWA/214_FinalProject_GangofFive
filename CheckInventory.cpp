#include "CheckInventory.h"


CheckInventory::CheckInventory(Staff *s, StaffCo_ordination *m) : Command(s, m) {}


void CheckInventory::execute()
{
	mediator->sendMessage("Checking inventory status", appointed, "CheckInventory");
}