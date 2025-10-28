#ifndef ROLES_H
#define ROLES_H
#include "Staff.h"

class Roles : public Staff {

public:
	vector<Staff*> staff;

	Roles();

	string jobDesc();

	string getType();
};

#endif
