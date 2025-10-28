#ifndef BASESTAFF_H
#define BASESTAFF_H
#include "Staff.h"

class BaseStaff : public Staff {


public:
	BaseStaff();

	string jobDesc();

	void handleCustomer(Request* req);

	string getType();
};

#endif
