#ifndef GARDENING_H
#define GARDENING_H
#include "Roles.h"

class Gardening : public Roles
{
  public:
    Gardening(Staff* s);
    virtual ~Gardening();
    std::string getType() override;
    std::string jobDesc() override;

    void update(Plant* p) override;
    void handleCustomer(Request* req) override;
    void handlePlant(Plant* p) override;
    void checkPlants();

    virtual void receive(string m, People* from, Nursery* group, string type);
  private:
    std::vector<Plant *> plants;
};

#endif  //GARDENING_H
