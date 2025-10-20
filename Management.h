#ifndef MANAGEMENT_H
#define MANAGEMENT_H

class Management : Roles {

public:
	Command* cmd;

	string getType();

	Management();

	void handleCustomer(Request* req);

	void assignTasks();
};

#endif
