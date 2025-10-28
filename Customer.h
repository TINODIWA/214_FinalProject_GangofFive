#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "People.h"
#include "Request.h"

class Order;

class Customer : public People {

private:
	Order* order;
	Request req;

public:
	Customer();
	~Customer();
	Customer(const Customer* other);
	void makeReq(Request* req);
	void placeOrder();
};

#endif
