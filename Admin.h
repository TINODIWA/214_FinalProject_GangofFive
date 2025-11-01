#ifndef ADMIN_H
#define ADMIN_H
#include "Roles.h"

class Admin : public Roles {

#include <iostream>
#include <string>

public:
	Admin(Staff* s);
	~Admin();
	std::string getType() override;
	std::string jobDesc() override;
	void updateInventory();
	void handleCustomer(Request* req) override;
	void handlePlant(Plant* p) override;

	virtual void receive(string m, People* from, Nursery* group, string type);
};

#endif  // ADMIN_H_
