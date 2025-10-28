/**
 * @file Payment.h
 * @author Swelihle Makhathini
 * @brief
 * @version 0.1
 * @date 2025-10-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
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