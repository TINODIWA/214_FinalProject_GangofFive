/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "Staff.h"
#include "StaffCo_ordination.h"

class StaffCo_ordination;
class Staff;

class Command {
 protected:
  Staff* appointed;
  StaffCo_ordination* mediator;

 public:
  Command(Staff* s, StaffCo_ordination* m);
  virtual ~Command();
  virtual void execute() = 0;
};

#endif  // COMMAND_H_
