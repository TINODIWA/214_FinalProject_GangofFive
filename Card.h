/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CARD_H_
#define CARD_H_

#include "Payment.h"
#include <iostream>

using namespace std;

class Card : public Payment {
 public:
  Card();
  ~Card();
  void prepare();
  void payment();
  string getType();
};

#endif  // CARD_H_
