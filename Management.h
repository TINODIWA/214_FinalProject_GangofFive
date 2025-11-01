#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "Roles.h"
#include "Command.h"

class Management : public Roles {

  public:
    Management(Nursery* n, std::string name);
    ~Management();
    std::string getType() override;
    std::string jobDesc() override;
    
    void handleCustomer(Request* req) override;
    void handlePlant(Plant* p) override;
    void assignTasks();
    void addCommand(Command* c);

  private:
	  std::vector<Command*> cmd;
};

#endif  // MANAGEMENT_H_
