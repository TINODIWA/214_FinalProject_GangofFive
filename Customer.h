/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

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
  explicit Customer(const Customer* other);
  void makeReq(Request* req);
};

#endif  // CUSTOMER_H_
