/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PAYMENT_H_
#define PAYMENT_H_

#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;

#include "Customer.h"
#include "Plant.h"
#include "Staff.h"

class Payment
{
private:
    virtual void prepare() = 0;
    virtual void payment() = 0;
    virtual string getType() = 0;
    

public:
    Payment();
    virtual ~Payment();
    string purchase(Customer *customer, map<Plant*,int> plants,Staff* staff);
    string receipt(Customer *customer, map<Plant*,int> plants,Staff* staff);
};

#endif
