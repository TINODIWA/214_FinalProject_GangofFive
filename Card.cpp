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
void Card::prepare()
{
    cout << "Awaiting Authorisation\n";
}

/**
 * @brief processing a Card payment
 *
 */
void Card::payment()
{
    cout << "Processing Payment\n";
}

/**
 * @brief returns the type of payment
 * 
 * @return string 
 */
string Card::getType(){
    return "Card Payment";
}

