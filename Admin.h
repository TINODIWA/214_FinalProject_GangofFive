/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ADMIN_H_
#define ADMIN_H_

#include <iostream>
#include <string>

class Admin : Roles {
   public:
    Admin();

    string handleCustomer(Request* req);

    void updateInventory();

    string getType();
};

#endif  // ADMIN_H_
