#ifndef SALES_H
#define SALES_H
#include "Roles.h"

class Sales : public Roles
{

public:
	Sales();
	~Sales();
	std::string getType() override;
	std::string jobDesc() override;
	void handleCustomer(Request* req) override;
	void handlePlant(Plant* p) override;
	void handleSales();
};

#endif  // SALES_H_
