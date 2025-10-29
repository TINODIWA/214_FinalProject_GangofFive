#ifndef BASESTAFF_H
#define BASESTAFF_H

#include "Staff.h"

#include <string>

class BaseStaff : public Staff {

public:
	BaseStaff();

	~BaseStaff();

	string jobDesc();

	void handleCustomer(Request* req);

	string getType();
};

#endif
