/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CASH_H_
#define CASH_H_

#include "Payment.h"
#include <iostream>

using namespace std;

class Cash : public Payment {
 public:
  Cash();
  ~Cash();
  void prepare();
  void payment();
  void package();
};

#endif  // CARD_H_
