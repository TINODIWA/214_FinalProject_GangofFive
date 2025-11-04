#ifndef BASESTAFF_H
#define BASESTAFF_H
#include "Staff.h"

#include <iostream>
#include <string>


class BaseStaff : public Staff {
 public:
  BaseStaff();
  BaseStaff(Nursery* n, std::string name);
  virtual ~BaseStaff();
  void update(Plant* p);       // stubbed
  void handlePlant(Plant* p);  // stubbed
  std::string jobDesc() override;
  void handleCustomer(Request req, Customer* customer) override;
  std::string getType() override;

  virtual void receive(string m, People* from, Nursery* group, string type);
};

#endif  // BASESTAFF_H_
