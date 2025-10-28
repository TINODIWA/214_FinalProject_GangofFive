#include "Order.h"


/**
 * @brief Construct a new Order:: Order object
 * 
 */
Order::Order() : customer(nullptr), paymentMethod(nullptr) {}

/**
 * @brief purchase and order
 * 
 */
void Order::purchase()
{
	cout << "Please select a payment method:\n";

	string choice;
	bool valid = false;

	while (!valid)
	{
		cout << "** Please type the payment method exactly as displayed below**\n";
		cout << "1. EFT\n";
		cout << "2. Card\n";
		cout << "3. Cash\n";

		cout << "Payment Method: ";
		cin >> choice;

		if (choice == "")
			continue;
		if (choice == "EFT")
		{
			paymentMethod = new EFT();
			valid = true;
		}
		else if (choice == "Card")
		{
			paymentMethod = new Card();
			valid = true;
		}
		else if (choice == "Cash")
		{
			paymentMethod = new Cash();
			valid = true;
		}
		else
		{
			cout << "Invalid payment method, please try again.\n";
		}
	}

	paymentMethod->purchase();
}

/**
 * @brief add a plant to the order
 * 
 * @param p 
 */
void Order::addPlant(Plant *p)
{
	if(!p) return;
	
	OrderPlant newPlant;

	newPlant.advice = "";
	newPlant.plant = p;
	try{
		++plants.at(newPlant);
	}
	catch(std::out_of_range err){
		plants[newPlant] = 1;
	}
}

/**
 * @brief remove a plant from the order
 * 
 * @param p 
 */
void Order::removePlant(Plant *p)
{
	OrderPlant rem;
	rem.plant = p;
	plants.erase(rem);
}
