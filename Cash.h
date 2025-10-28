/**
 * @file Cash.h
 * @author Swelihle Makhathini
 * @brief
 * @version 0.1
 * @date 2025-10-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CASH_H
#define CASH_H

#include <iostream>
#include "Payment.h"

using namespace std;

class Cash : public Payment {
   public:
    Cash();
    ~Cash();
    void prepare();
    void payment();
    void package();
};

#endif
