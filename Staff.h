#ifndef STAFF_H
#define STAFF_H
#include "People.h"
#include "Request.h"
class Plant;
class Staff : public People {

private:
	string name;
	string level;
	vector<string> responsibilities;
	Staff* successor;

public:
	virtual void handlePlant(Plant* p);

	void handleCustomer(Request* req);

	Staff();

	~Staff();

	Staff(const Staff& other);

	virtual string jobDesc() = 0;

	virtual string getType() = 0;

	virtual void update(Plant* p) = 0;
};

#endif
