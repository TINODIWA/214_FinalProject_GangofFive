#ifndef MANAGESALES_H
#define MANAGESALES_H

#include "Command.h"

class ManageSales : public Command {
   public:
    ManageSales(Staff* s, StaffCo_ordination* m);
    virtual void execute();
};

#endif
