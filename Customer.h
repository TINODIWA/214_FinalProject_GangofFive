/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "People.h"
#include "Request.h"
#include <iostream>

using namespace std;

class Order;

class Customer : public People {
 private:
  Order* order;
  Request* req;

 public:
  Customer(string name);
  ~Customer();
  Customer(const Customer* other);
  void makeReq(Request req);
};

#endif  // CUSTOMER_H_
