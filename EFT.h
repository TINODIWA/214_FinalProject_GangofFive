/**
 * @file EFT.h
 * @author Swelihle Makhathini
 * @brief 
 * @version 0.1
 * @date 2025-10-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef EFT_H
#define EFT_H

#include <iostream>
#include "Payment.h"

using namespace std;

class EFT : public Payment
{

public:
    EFT();
    ~EFT();
    void prepare();
    void payment();
    void package();
};
#endif
