/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef MANAGEMENT_H_
#define MANAGEMENT_H_
#include <string>

class Management : Roles {
   public:
    Command* cmd;

    string getType();

    Management();

    void handleCustomer(Request* req);

    void assignTasks();
};

#endif  // MANAGEMENT_H_
