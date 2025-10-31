/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef BASESTAFF_H_
#define BASESTAFF_H_

#include "Staff.h"
#include <iostream>
#include <string>

class BaseStaff : public Staff {
 public:
  BaseStaff();
  virtual ~BaseStaff();
  virtual string jobDesc();
  virtual void handleCustomer(Request* req);
  virtual string getType();
};

#endif  // BASESTAFF_H_
