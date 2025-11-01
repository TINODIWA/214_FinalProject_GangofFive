#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "Roles.h"
#include "Command.h"

class Management : public Roles {

public:
	Management();
	~Management();
	std::string getType() override;
	std::string jobDesc() override;
	Command* cmd;
	void handleCustomer(Request* req) override;
	void handlePlant(Plant* p) override;
	void assignTasks();
};

#endif  // MANAGEMENT_H_
