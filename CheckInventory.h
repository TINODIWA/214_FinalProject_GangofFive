#ifndef CHECKINVENTORY_H
#define CHECKINVENTORY_H

#include "Command.h"

class CheckInventory : public Command {
	public:
		CheckInventory(Staff* s, StaffCo_ordination* m);
		virtual void execute();
};

#endif
