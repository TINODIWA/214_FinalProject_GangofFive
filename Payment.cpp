
/**
 * @file Payment.cpp
 * @author Swelihle Makhathini
 * @brief Implementation of the Payment class which handles payment processing and receipt generation for plant orders
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
/**
 * @brief Process a purchase transaction
 * @param customer The customer making the purchase
 * @param plants Map of plants and their quantities being purchased
 * @param staff Staff member handling the transaction
 * @return string The transaction receipt
 */
string Payment::purchase(Customer* customer, map<Plant*, int> plants, Staff* staff) {
  prepare();
  payment();
  return receipt(customer, plants, staff);
}

/**
 * @brief Generate a receipt for the purchase
 * @param customer The customer who made the purchase
 * @param plants Map of plants and their quantities purchased
 * @param staff Staff member who handled the transaction
 * @return string Formatted receipt as a string
 */
string Payment::receipt(Customer* customer, map<Plant*, int> plants, Staff* staff) {
  stringstream receipt;

  receipt << "Customer Copy\n";
  receipt << "---------------------------\n";
  receipt << ((People*)staff)->getName() << "\n";
  receipt << "Customer: " << customer->getName() << "\n";
  receipt << "---------------------------\n";
  receipt << "Payment Method: " << getType() << "\n";
  receipt << "Order:\n";

  int total = 0;
  receipt << left << setw(10) << "Item";
  receipt << left << setw(5) << "QTY";
  receipt << left << setw(2) << "Price(R)" << "\n";
  receipt << "\n";

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

  receipt << "A little advice on how to care for your plant(s)\n";

  string type = (*plants.begin()).first->getName();
  it = plants.begin();
  receipt << (*it).first->advice();
  ++it;

  while (it != plants.end()) {
    string name = (*it).first->getName();
    if (name != type) {
      receipt << (*it).first->advice()<<"\n";
      type = name;
    }
    ++it;
  }

  return receipt.str();
}
