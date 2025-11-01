#ifndef ADMIN_H
#define ADMIN_H

class Admin : Roles {


public:
	Admin();

	string handleCustomer(Request* req);

	void updateInventory();

	string getType();
};

#endif
