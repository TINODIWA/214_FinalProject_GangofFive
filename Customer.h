#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer : People {

private:
	Order* order;
	Request req;

public:
	Customer();

	void makeReq(Request* req);
};

#endif
