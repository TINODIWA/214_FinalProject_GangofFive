/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef MANAGESALES_H_
#define MANAGESALES_H_

#include "Command.h"

class ManageSales : public Command {
   public:
    ManageSales(Staff* s, StaffCo_ordination* m);
    virtual void execute();
};

#endif  // MANAGESALES_H_
