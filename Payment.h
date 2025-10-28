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
using namespace std;

class Payment {
   private:
    virtual void prepare() = 0;
    virtual void payment() = 0;
    virtual void package() = 0;

   public:
    Payment();
    virtual ~Payment();
    void purchase();
};

#endif