#ifndef ORDER_H
#define ORDER_H

#include <map>
#include "Plant.h"
#include "Customer.h"
#include "Staff.h"
#include "Payment.h"
#include "EFT.h"
#include "Card.h"
#include "Cash.h"

using namespace std;


struct OrderPlant{
	Plant* plant;
	string advice;

	bool operator==(const Plant* p){
		return p == plant;
	}
};

class Order {

private:
	map<OrderPlant,int> plants;
	Customer* customer;
	Staff* staff;
	string receipt;
	Payment* paymentMethod;

public:
	Order();
	~Order();
	Order(const Order& other);

private:
	void prepare();
	void payment();
	Order* package();

public:

	void addPlant(Plant* p);
	void removePlant(Plant* p);
	void purchase();
};

#endif
