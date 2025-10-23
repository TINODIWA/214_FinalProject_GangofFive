#ifndef NURSERY_H
#define NURSERY_H

#include "Plant.h"
#include "Customer.h"
#include "Staff.h"

#include <vector>

using namespace std;

class Nursery {
	public:
		Nursery();
		void addPlant(Plant* p);
		void removePlant(Plant* p);
		void start(bool sim);
		void addStaff(Staff* s);
		void removeStaff(Staff* s);
		void notify();
	
	private:
		vector<vector<Plant*>> plants;
		vector<Customer*> customers;
		vector<Staff*> staff;

		// needs to be added
		// Inventory* inventory;
};

#endif
