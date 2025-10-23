#include "CheckPlant.h"


CheckPlant::CheckPlant(Staff *s, StaffCo_ordination *m) : Command(s, m) {}


void CheckPlant::execute()
{
	mediator->sendMessage("Checking plant status", appointed, "CheckPlant");
}