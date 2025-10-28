#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "Roles.h"
#include "Command.h"

class Management : public Roles {

public:
	Command* cmd;

	string getType();

	Management();

	void handleCustomer(Request* req);

	void assignTasks();
};

#endif
