/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef EFT_H_
#define EFT_H_

#include "Payment.h"
#include <iostream>

using namespace std;

class EFT : public Payment {
 public:
  EFT();
  ~EFT();
  void prepare();
  void payment();
  void package();
};
#endif  // EFT_H_
