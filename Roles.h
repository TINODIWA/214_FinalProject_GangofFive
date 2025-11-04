#ifndef ROLES_H
#define ROLES_H

#include "Staff.h"

class Roles : public Staff {
  public:
    Roles(Nursery* n, std::string name, Staff* s);
    virtual ~Roles();
    virtual std::string jobDesc();
    virtual std::string getType();
    virtual void update(Plant* p);
    virtual void receive(string m, People* from, Nursery* group, string type);

  protected:
    // std::vector<Staff*> staff;
    Staff* staff;
};

#endif  // ROLES_H_
