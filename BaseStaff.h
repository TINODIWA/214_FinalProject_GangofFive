#ifndef BASESTAFF_H
#define BASESTAFF_H

#include <string>

class BaseStaff : Staff {
   public:
    BaseStaff();

    string jobDesc();

    void handleCustomer(Request* req);

    string getType();
};

#endif
