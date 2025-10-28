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
void Payment::purchase()
{
    prepare();
    payment();
    package();
    cout << "Purchase complete.\n";
}
