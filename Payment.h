/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PAYMENT_H_
#define PAYMENT_H_

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

#endif  // PAYMENT_H_
