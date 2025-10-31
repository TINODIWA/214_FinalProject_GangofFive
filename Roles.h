#ifndef ROLES_H
#define ROLES_H
#include "Staff.h"

class Roles : public Staff {

public:
	vector<Staff*> staff;
	Roles();
	virtual ~Roles();
	virtual std::string jobDesc() override = 0;
	virtual std::string getType() override = 0;
};

#endif  // ROLES_H_
