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
  StaffCo_ordination(Garden* g);
  virtual ~StaffCo_ordination();

  virtual void sendMessage(string m, People* from, string type);
  virtual void sendMessage(string m, People* to, People* from, string type);
  virtual void addStaff(Staff* s);
  virtual void removeStaff(Staff* s);
  virtual string getName() const;
};

#endif  // STAFFCO_ORDINATION_H_
