#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "Roles.h"
#include "Command.h"
#include "CheckInventory.h"
#include "CheckPlant.h"
#include "HireStaff.h"
#include "FireStaff.h"
#include <iostream>
#include <string>

class Management : public Roles {

  public:
    Management(Staff* s);
    virtual ~Management();
    std::string getType() override;
    std::string jobDesc() override;
    
    void handleCustomer(Request* req) override;
    void hireStaff(Staff* newStaff);
    void fireStaff(Staff* exStaff);
    void assignTasks(Nursery* group);

    virtual void receive(string m, People* from, Nursery* group, string type);

  private:
	  Command* cmd;
};

#endif  // MANAGEMENT_H_
