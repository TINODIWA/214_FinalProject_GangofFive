#ifndef BASESTAFF_H
#define BASESTAFF_H
#include "Staff.h"

class BaseStaff : public Staff {

#include <string>

class BaseStaff : Staff {
 public:
  BaseStaff();

	std::string jobDesc() override;
	void handleCustomer(Request* req) override;
	void handlePlant(Plant* p) override;
	std::string getType() override;
};

#endif  // BASESTAFF_H_
