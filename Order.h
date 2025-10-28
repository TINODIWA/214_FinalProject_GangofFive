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

class Order
{

private:
	map<Plant *, int> plants;
	Customer *customer;
	Staff *staff;
	string receipt;
	Payment *paymentMethod;
	int purchaseDate;

public:
	Order();
	Order(Customer *customer, Staff *staff);
	~Order();
	Order(const Order &other);
	void addPlant(Plant *p);
	void removePlant(Plant *p);
	void purchase();
	void setStaff(Staff* s);
	void setCustomer(Customer* c);

private:
	void prepare();
	void payment();
	Order *package();

};

#endif
