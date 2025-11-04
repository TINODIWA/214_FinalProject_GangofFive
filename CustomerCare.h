/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CUSTOMERCARE_H_
#define CUSTOMERCARE_H_

#include "Nursery.h"
#include <iostream>
#include <string>

class CustomerCare : public Nursery {
 public:
  void notify();

  CustomerCare();
};

#endif  // CUSTOMERCARE_H_
