/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CUSTOMERCARE_H_
#define CUSTOMERCARE_H_

#include "Nursery.h"
#include <iostream>
#include <string>
class Request;
class CustomerCare : public Nursery {
 private:
  void setChain();
  Staff* chain;

 public:
  void notify(Request* req);  // I think this would functioin sa my setCollegues thing...
  void notify();

  CustomerCare();
};

#endif  // CUSTOMERCARE_H_
