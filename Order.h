#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "Plant.h"
#include "Customer.h"

using namespace std;

class Order {

private:
	vector<Plant*> plants;
	Customer* customer;

public:
	Order();
	~Order();
	Order(const Order& other);

private:
	void prepare();
	void payment();
	void package();

public:

	void addPlant(Plant* p);

	void removePlant(Plant* p);

	void purchase();
};

#endif
