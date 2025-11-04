#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "Roles.h"
#include "Command.h"

class Management : public Roles {

  public:
    Management(Staff* s);
    ~Management();
    std::string getType() override;
    std::string jobDesc() override;
    
    void handleCustomer(Request* req) override;
    void handlePlant(Plant* p) override;
    void assignTasks();
    void addCommand(Command* c);

    virtual void receive(string m, People* from, Nursery* group, string type);

  private:
	  std::vector<Command*> cmd;
};

#endif  // MANAGEMENT_H_
