/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef BASESTAFF_H_
#define BASESTAFF_H_

#include <string>

class BaseStaff : Staff {
   public:
    BaseStaff();

    string jobDesc();

    void handleCustomer(Request* req);

    string getType();
};

#endif  // BASESTAFF_H_
