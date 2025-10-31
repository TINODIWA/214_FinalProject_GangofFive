/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef MANAGEMENT_H_
#define MANAGEMENT_H_
#include <string>
#include <iostream>

#include "Roles.h"
#include "Command.h"

class Management : public Roles {
  private:
    virtual string getType();
    Management();
    virtual ~Management();
    void handleCustomer(Request* req);
    void assignTasks();
  public:
    Command* cmd;
};

#endif  // MANAGEMENT_H_
