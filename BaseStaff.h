#ifndef BASESTAFF_H
#define BASESTAFF_H

class BaseStaff : Staff {


public:
	BaseStaff();

	string jobDesc();

	void handleCustomer(Request* req);

	string getType();
};

#endif
