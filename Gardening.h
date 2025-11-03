#ifndef GARDENING_H
#define GARDENING_H
#include "Roles.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Gardening : public Roles
{
  public:
    Gardening(Staff* s);
    virtual ~Gardening();
    std::string getType() override;
    std::string jobDesc() override;
    
    void update();
    void handleCustomer(Request* req) override;
    void handlePlant(Plant* p);
    void checkPlants();

    virtual void receive(string m, People* from, Nursery* group, string type);
  private:
    std::vector<Plant *> plants;
};

#endif  // GARDENING_H_
