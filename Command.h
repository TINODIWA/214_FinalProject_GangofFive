#ifndef COMMAND_H
#define COMMAND_H

#include "Staff.h"
#include "StaffCo_ordination.h"

class StaffCo_ordination;
class Staff;

class Command {
	protected:
		Staff* appointed;
		StaffCo_ordination* mediator;

	public:
		Command(Staff* s, StaffCo_ordination* m);
		virtual ~Command();
		virtual void execute() = 0;
};

#endif
