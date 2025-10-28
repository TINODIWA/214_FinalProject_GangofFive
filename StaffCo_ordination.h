#ifndef STAFFCO_ORDINATION_H
#define STAFFCO_ORDINATION_H

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

#endif
