/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef NURSERY_H_
#define NURSERY_H_

#include <iostream>
#include <vector>

#include "Plant.h"
#include "Garden.h"
class Customer;
class Staff;
class People;

using namespace std;

class Nursery {
 public:
  vector<string> complaints;
  Nursery();
  Nursery(GardenPlot* g);
  virtual ~Nursery();
  Nursery(const Nursery& other);
  void start(bool sim);
  virtual void addStaff(Staff* s) = 0;
  virtual void removeStaff(Staff* s) = 0;
  virtual void addCustomer(Customer* c) = 0;
  virtual void removeCustomer(Customer* c) = 0;
  virtual void sendMessage(string m, People* from, string type) = 0;
  virtual void sendMessage(string m, People* to, People* from, string type) = 0;
  void setGarden(GardenPlot* g);
  GardenPlot* getGarden();
  vector<Staff*> getStaff();
  int getDay();
  int updateDay();
  virtual string getName() const = 0;
  virtual void setChain();

  Staff* findStaffByType(const string& type);

  protected:
    Garden* garden;
    vector<Customer*> customers;
    vector<Staff*> staff;
};

#endif  // NURSERY_H_
