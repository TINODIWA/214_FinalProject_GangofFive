#ifndef STAFF_H
#define STAFF_H

class Staff : People {

private:
	string name;
	string level;
	vector<string> responsibilities;
	Staff successor;

public:
	void handlePlant(Plant* p);

	void handleCustomer(Request* req);

	Staff();

	string JobDesc();

	string getType();
};

#endif
