#ifndef BASESTAFF_H
#define BASESTAFF_H
#include "Staff.h"

#include <iostream>
#include <string>

class BaseStaff : public Staff {
 public:
  BaseStaff();
  BaseStaff(Nursery* n, std::string name);
  virtual ~BaseStaff();

	std::string jobDesc() override;
	void handleCustomer(Request* req) override;
	std::string getType() override;

  virtual void receive(string m, People* from, Nursery* group, string type);
};

#endif  // BASESTAFF_H_
