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

	void makeReq(Request* req);
};

#endif
