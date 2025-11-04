/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CHECKINVENTORY_H_
#define CHECKINVENTORY_H_

#include "Command.h"
#include "Nursery.h"

class CheckInventory : public Command {
 public:
  CheckInventory(Staff* from, Nursery* m);
  virtual void execute();
};

#endif  // CHECKINVENTORY_H_
