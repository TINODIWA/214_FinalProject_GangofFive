#ifndef ADMIN_H
#define ADMIN_H
#include "Roles.h"

class Admin : public Roles {


public:
	Admin();
	~Admin();
	std::string getType() override;
	std::string jobDesc() override;
	void updateInventory();
	void handleCustomer(Request* req) override;
	void handlePlant(Plant* p) override;
};

#endif
