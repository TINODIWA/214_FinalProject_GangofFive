/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "People.h"
#include "Request.h"
#include <iostream>
#include <vector>

using namespace std;

class Order;

class Customer : public People {
 private:
  vector<Order*> order;
  //Request req;

 public:
  Customer(string name);
  ~Customer();
  Customer(const Customer* other);
  void makeReq(Request req);
  void receive(string m, People* from, Nursery* group, string type);
};

#endif  // CUSTOMER_H_
