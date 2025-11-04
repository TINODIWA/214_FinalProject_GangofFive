
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
 * @brief processing purchasing an order of plants
 *
 * @return string
 */
string Payment::purchase(Customer* customer, map<Plant*, int> plants, Staff* staff) {
  prepare();
  payment();
  return receipt(customer, plants, staff);
}

string Payment::receipt(Customer* customer, map<Plant*, int> plants, Staff* staff) {
  stringstream receipt;

  receipt << "Customer Copy\n";
  receipt << "---------------------------\n";
  receipt << staff->getName() << "\n";
  receipt << "Customer: " << customer->getName() << "\n";
  receipt << "---------------------------\n";
  receipt << "Payment Method: " << getType() << "\n";
  receipt << "Order:\n";

  int total = 0;
  receipt << left << setw(10) << "Item";
  receipt << left << setw(5) << "QTY";
  receipt << left << setw(2) << "Price(R)"<< "\n";
  receipt <<"\n";

  map<Plant*, int>::iterator it = plants.begin();
  while (it != plants.end()) {
    receipt << left << setw(10) << (*it).first->getName();
    receipt << left << setw(5) << (*it).second;
    receipt << left << setw(2) << "R" << (*it).first->getPrice() << "\n";

    total += (*it).first->getPrice() * (*it).second;
    ++it;
  }

  receipt << "\nTotal: R" << total << "\n";
  receipt << "---------------------------\n";

  return receipt.str();
}
