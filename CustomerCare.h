/**
 * @copyright Copyright (c) 2025
 */

#ifndef CUSTOMERCARE_H_
#define CUSTOMERCARE_H_

#include <string>
#include <vector>

#include "Nursery.h"

class People;
class Staff;
class Customer;
class Request;

// CustomerCare is a mediator for customer-to-staff communications.
// It also configures a Chain of Responsibility among staff for handling customer requests.
class CustomerCare : public Nursery {
 private:
  //void setChain();
  Staff* chain;

 public:
  void notify(Request req);  // I think this would functioin sa my setCollegues thing...
  CustomerCare();
  CustomerCare(Garden* g);
  virtual ~CustomerCare();

  virtual void addStaff(Staff* s);
  virtual void removeStaff(Staff* s);
  virtual void addCustomer(Customer* c);
  virtual void removeCustomer(Customer* c);
  virtual void sendMessage(std::string m, People* from, std::string type);
  virtual void sendMessage(std::string m, People* to, People* from, std::string type);
  virtual string getName() const;

  // Chain of Responsibility configuration: set the successor order.
  // The first element becomes the head of the chain.
  void setChain(const std::vector<Staff*>& order);

  // Route a concrete Request to the head of chain (if configured)
  void routeRequest(Request req, Customer* from);

 private:
  Staff* chainHead = NULL;
};

#endif  // CUSTOMERCARE_H_
