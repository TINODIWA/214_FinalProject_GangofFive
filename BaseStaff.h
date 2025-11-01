#ifndef BASESTAFF_H
#define BASESTAFF_H
#include "Staff.h"

#include <string>

class BaseStaff : public Staff {
 public:
  BaseStaff();
  BaseStaff(Nursery* n, std::string name);
  virtual ~BaseStaff();

	std::string jobDesc() override;
	void handleCustomer(Request* req) override;
	void handlePlant(Plant* p) override;
	std::string getType() override;
};

#endif  // BASESTAFF_H_
