
/**
 * @file Payment.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Payment.h"

// PAYMENT

/**
 * @brief Construct a new Payment:: Payment object
 *
 */
Payment::Payment() {}

/**
 * @brief Destroy the Payment:: Payment object
 *
 */
Payment::~Payment() {}

/**
 * @brief process of purchasing an order
 *
 */
void Payment::purchase() {
  prepare();
  payment();
  package();
  cout << "Purchase complete.\n";
}
