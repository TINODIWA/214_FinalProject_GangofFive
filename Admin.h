#ifndef ADMIN_H
#define ADMIN_H
#include "Roles.h"

class Admin : public Roles {
#include <iostream>
#include <string>

 public:
  Admin(Staff* s);
  virtual ~Admin();
  std::string getType() override;
  std::string jobDesc() override;
  void updateInventory();
  void handleCustomer(Request req, Customer* customer) override;
  void update(Plant* p);       // stubbed
  void handlePlant(Plant* p);  // stubbed

  virtual void receive(string m, People* from, Nursery* group, string type);
};

#endif  // ADMIN_H_
