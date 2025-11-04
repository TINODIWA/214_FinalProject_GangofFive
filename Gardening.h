#ifndef GARDENING_H
#define GARDENING_H
#include "Roles.h"
#include <map>

class Gardening : public Roles
{
  public:
    Gardening(Staff* s);
    virtual ~Gardening();
    std::string getType() override;
    std::string jobDesc() override;
    
    void update(Plant* p);
    void handleCustomer(Request req, Customer* customer) override;
    void handlePlant(Plant* p);
    void checkPlants();
    //addCrop(): 

    virtual void receive(string m, People* from, Nursery* group, string type);
  private:
    std::vector<Plant *> plants;
};

#endif  // GARDENING_H_
