#include "ManageSales.h"


ManageSales::ManageSales(Staff *s, StaffCo_ordination *m) : Command(s, m) {}


void ManageSales::execute()
{
	mediator->sendMessage("Managing sales", appointed, "ManageSales");
}