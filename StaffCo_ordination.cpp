#include "StaffCo_ordination.h"

//Assume all commands come from the manager for now


StaffCo_ordination::StaffCo_ordination() : Nursery() {}


void StaffCo_ordination::sendMessage(string message, Staff* to, string type) {
	if(to == NULL || (to->getType() != "Gardener" && to->getType() != "Sales" && to->getType() != "Admin")) return;
	cout <<  "Manager is asking " << to->getType() << " to: " << message << endl;

	to->receive(type);
}
