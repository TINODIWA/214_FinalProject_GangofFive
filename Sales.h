/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef SALES_H_
#define SALES_H_
#include <string>

class Sales : Roles {
 public:
  string handleCustomer(Request* req);

  void handleSales();

  Sales();

  string getType();
};

#endif  // SALES_H_
