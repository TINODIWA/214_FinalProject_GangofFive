#ifndef SALES_H
#define SALES_H
#include "Roles.h"

class Sales : public Roles
{

public:
  Sales(Staff* s);
  virtual ~Sales();
	std::string getType() override;
	std::string jobDesc() override;
	void handleCustomer(Request* req) override;
	void handlePlant(Plant* p) override;

  virtual void receive(string m, People* from, Nursery* group, string type);
};

#endif  // SALES_H_
