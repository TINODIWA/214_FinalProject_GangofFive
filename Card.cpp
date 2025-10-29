/**
 * @file Card.cpp
 * @author Swelihle Makhathini
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Card.h"

/**
 * @brief Construct a new Card:: Card object
 *
 */
Card::Card() : Payment() {}

/**
 * @brief Destroy the Card:: Card object
 *
 */
Card::~Card() {}

/**
 * @brief preparing a Card order
 *
 */
void Card::prepare() {
  cout << "Awaiting Authorisation\n";
}

/**
 * @brief processing a Card payment
 *
 */
void Card::payment() {
  cout << "Processing Payment\n";
}

/**
 * @brief packaging a Card order
 *
 */
void Card::package() {}
