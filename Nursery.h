#ifndef NURSERY_H
#define NURSERY_H

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

#endif
