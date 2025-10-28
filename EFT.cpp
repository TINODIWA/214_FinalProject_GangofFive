#include "EFT.h"

/**
 * @brief Construct a new EFT::EFT object
 *
 */
EFT::EFT() : Payment() {}

/**
 * @brief Destroy the EFT::EFT object
 *
 */
EFT::~EFT() {}

/**
 * @brief prepares EFT payment
 *
 */
void EFT::prepare()
{
	cout << "Connecting to your Bank...\n";
	cout << "Connected Successfully!\n";
}

/**
 * @brief processes EFT payment
 *
 */
void EFT::payment()
{
	cout << "Transfer in Process...\n";
	cout << "Transfer Complete!\n";
}

/**
 * @brief packages EFT payment
 *
 */
void EFT::package()
{
}
