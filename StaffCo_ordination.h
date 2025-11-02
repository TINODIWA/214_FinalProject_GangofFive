/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef STAFFCO_ORDINATION_H_
#define STAFFCO_ORDINATION_H_

#include "Nursery.h"
#include "Staff.h"

#include <iostream>
#include <string>
using namespace std;

class StaffCo_ordination : public Nursery {
 public:
  StaffCo_ordination();
  void sendMessage(string message, Staff* to, string type);
};

#endif  // STAFFCO_ORDINATION_H_
