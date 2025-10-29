/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CHECKINVENTORY_H_
#define CHECKINVENTORY_H_
#include "Command.h"

class CheckInventory : public Command {
 public:
  CheckInventory(Staff* s, StaffCo_ordination* m);
  virtual void execute();
};

#endif  // CHECKINVENTORY_H_
