/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ROLES_H_
#define ROLES_H_
#include <string>
#include <vector>

#include "Staff.h"
#include "Roles.h"
using namespace std;

class Roles : public Staff {
  public:
    Roles();
    virtual ~Roles();
    virtual string jobDesc() = 0;
    virtual string getType() = 0;

  private:
    vector<Staff*> staff;
};

#endif  // ROLES_H_
