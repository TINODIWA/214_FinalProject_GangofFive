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
 public:
  void notify(Request req, Customer* customer);  // I think this would functioin sa my setCollegues thing...
  CustomerCare();
  CustomerCare(GardenPlot* g);
  virtual ~CustomerCare();

  virtual void addStaff(Staff* s);
  virtual void removeStaff(Staff* s);
  virtual void addCustomer(Customer* c);
  virtual void removeCustomer(Customer* c);
  virtual void sendMessage(std::string m, People* from, std::string type);
  virtual void sendMessage(std::string m, People* to, People* from, std::string type);
  virtual string getName() const;
  void setChain();


 private:
  Staff* chainHead = NULL;
  
};

#endif  // CUSTOMERCARE_H_
