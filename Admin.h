#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>

class Admin : Roles {
   public:
    Admin();

    string handleCustomer(Request* req);

    void updateInventory();

    string getType();
};

#endif
