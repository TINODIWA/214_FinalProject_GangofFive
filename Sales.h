#ifndef SALES_H
#define SALES_H
#include "Roles.h"

class Sales : public Roles {


public:
	string handleCustomer(Request* req);

	void handleSales();

	Sales();

	string getType();
};

#endif
