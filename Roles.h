#ifndef ROLES_H
#define ROLES_H

#include "Staff.h"

class Roles : public Staff {
  public:
    Roles(Nursery* n, std::string name);
    virtual ~Roles();
    virtual std::string jobDesc();
    virtual std::string getType();

  protected:
    std::vector<Staff*> staff;
};

#endif  // ROLES_H_
