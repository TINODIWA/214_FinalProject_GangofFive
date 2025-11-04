/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ORDER_H_
#define ORDER_H_

#include <map>
#include "Plant.h"
#include "Customer.h"
#include "Staff.h"
#include "Payment.h"
#include "EFT.h"
#include "Card.h"
#include "Cash.h"
#include <sstream>

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
	void purchase(int day);
	void setStaff(Staff* s);
	void setCustomer(Customer* c);
	string printOldOrder();
	map<Plant *, int> getPlants();
	void clearOrder();
};

#endif  // ORDER_H_
