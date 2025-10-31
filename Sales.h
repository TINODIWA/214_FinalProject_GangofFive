/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef SALES_H_
#define SALES_H_

#include "Roles.h"
#include <iostream>
#include <string>

class Sales : public Roles {
  public:
    Sales();
    virtual ~Sales();
    string handleCustomer(Request* req);
    int handleSales();
    string getType();
};

#endif  // SALES_H_
