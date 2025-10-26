#ifndef NURSERY_H
#define NURSERY_H
class Customer;
class Plant;
class Staff;
#include <vector>
using namespace std;
class Nursery {

public:
	vector<vector<Plant*>> plants;
	vector<Customer*> customers;
	vector<Staff*> staff;

	Nursery();

	void addPlant(Plant* p);

	void removePlant(Plant* p);

	void start(bool sim);

	void addStaff(Staff* s);

	void removeStaff(Staff* s);

	void notify();
};

#endif
