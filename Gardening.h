#ifndef GARDENING_H
#define GARDENING_H
#include "Roles.h"

class Gardening : public Roles
{
  public:
    Gardening(Nursery* n, std::string name);
    virtual ~Gardening();
    std::string getType() override;
    std::string jobDesc() override;
    
    void update();
    void handleCustomer(Request* req) override;
    void handlePlant(Plant* p) override;
    void checkPlants();
    
  private:
    std::vector<Plant *> plants;
};

#endif  // GARDENING_H_
