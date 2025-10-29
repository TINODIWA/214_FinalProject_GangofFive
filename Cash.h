/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CASH_H_
#define CASH_H_

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

#endif  // CARD_H_
