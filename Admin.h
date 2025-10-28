#ifndef ADMIN_H
#define ADMIN_H
#include "Roles.h"

class Admin : public Roles {


public:
	Admin();

	string handleCustomer(Request* req);

	void updateInventory();

	string getType();
};

#endif
