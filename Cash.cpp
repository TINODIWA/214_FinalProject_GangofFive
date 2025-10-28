#include "Cash.h"

/**
 * @brief Construct a new Cash:: Cash object
 *
 */
Cash::Cash() : Payment() {}

/**
 * @brief Destroy the Cash:: Cash object
 *
 */
Cash::~Cash() {}

/**
 * @brief preparing a Cash order
 *
 */
void Cash::prepare()
{
	cout << "Counting Cash\n";
}

/**
 * @brief processing a Card payment
 *
 */
void Cash::payment()
{
	cout << "Confirming purchase\n";
}

/**
 * @brief returns the type of payment
 * 
 * @return string 
 */

string Cash::getType(){
	return "Cash Payment";
}

