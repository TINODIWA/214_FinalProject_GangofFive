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

class Customer;
class Plant;
class Staff;

class Payment
{
private:
    virtual void prepare() = 0;
    virtual void payment() = 0;
    virtual string getType() = 0;
    

public:
    Payment();
    virtual ~Payment();
    string purchase(Customer *customer, vector<Plant *> plants,Staff* staff);
    string receipt(Customer *customer, vector<Plant *> plants,Staff* staff);
};

#endif