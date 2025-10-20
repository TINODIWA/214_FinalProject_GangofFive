#ifndef ROLES_H
#define ROLES_H

class Roles : Staff {

public:
	vector<Staff*> staff;

	Roles();

	string jobDesc();

	string getType();
};

#endif
