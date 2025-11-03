#ifndef SALES_H
#define SALES_H
#include "Roles.h"

class Sales : public Roles {
 public:
  Sales(Staff* s);
  virtual ~Sales();
  std::string getType() override;
  std::string jobDesc() override;
  void handleCustomer(Request req, Customer* customer) override;
  void update(Plant* p);       // stubbed
  void handlePlant(Plant* p);  // stubbed

  virtual void receive(string m, People* from, Nursery* group, string type);
};

#endif  // SALES_H_
