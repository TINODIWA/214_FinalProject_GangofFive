#ifndef NURSERY_H
#define NURSERY_H

class Nursery {

public:
	vector<vector<Plants*>> plants;
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
