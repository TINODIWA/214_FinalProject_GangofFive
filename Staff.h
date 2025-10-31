#ifndef STAFF_H
#define STAFF_H
#include "People.h"
#include "Request.h"

class Plant;
class Staff : public People
{

private:
	string name;
	string level;
	vector<string> responsibilities;

protected:
	Staff *successor;

public:
	Staff();
	Staff(const Staff *other);
	~Staff();
	void setSuccessor(Staff *succ);
	virtual std::string jobDesc() = 0;
	virtual std::string getType() = 0;
	virtual void handlePlant(Plant *p) = 0;
	virtual void handleCustomer(Request *req) = 0;
};

#endif
