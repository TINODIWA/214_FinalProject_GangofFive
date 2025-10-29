/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include "Payment.h"

using namespace std;

class Card : public Payment {
 public:
  Card();
  ~Card();
  void prepare();
  void payment();
  void package();
};

#endif  // CARD_H_
