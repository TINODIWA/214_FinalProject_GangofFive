/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef NURSERY_H_
#define NURSERY_H_

#include <iostream>
#include <vector>

#include "Plant.h"
class Customer;
class Staff;

using namespace std;

class Nursery {
 public:
  vector<vector<Plant*>> plants;
  vector<Customer*> customers;
  vector<Staff*> staff;

  Nursery();
  ~Nursery();
  Nursery(const Nursery& other);
  void addPlant(Plant* p);
  void removePlant(Plant* p);
  void start(bool sim);
  void addStaff(Staff* s);
  void removeStaff(Staff* s);
  void notify();
};

#endif  // NURSERY_H_
