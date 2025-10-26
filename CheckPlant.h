#ifndef CHECKPLANT_H
#define CHECKPLANT_H

#include "Command.h"

class CheckPlant : public Command {
	public:
		CheckPlant(Staff* s, StaffCo_ordination* m);
		virtual void execute();
};

#endif
