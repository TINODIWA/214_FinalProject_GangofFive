#ifndef SALES_H
#define SALES_H
#include "Roles.h"

class Sales : public Roles
{

public:
	Sales();
  Sales(Nursery* n, std::string name);
  virtual~Sales();
	std::string getType() override;
	std::string jobDesc() override;
	void handleCustomer(Request* req) override;
	void handlePlant(Plant* p) override;
};

#endif  // SALES_H_
