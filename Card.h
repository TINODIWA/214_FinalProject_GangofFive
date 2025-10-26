/**
 * @file Card.h
 * @author Swelihle Makhathini
 * @brief 
 * @version 0.1
 * @date 2025-10-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include "Payment.h"

using namespace std;

class Card : public Payment
{
public:
    Card();
    ~Card();
    void prepare();
    void payment();
    void package();
};


#endif
