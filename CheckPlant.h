/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CHECKPLANT_H_
#define CHECKPLANT_H_

#include "Command.h"

class CheckPlant : public Command {
 public:
  CheckPlant(Staff* s, StaffCo_ordination* m);
  virtual void execute();
};

#endif  // CHECKPLANT_H_
