#ifndef SALES_H
#define SALES_H

class Sales : Roles {


public:
	string handleCustomer(Request* req);

	void handleSales();

	Sales();

	string getType();
};

#endif
