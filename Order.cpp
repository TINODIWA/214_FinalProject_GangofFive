#include "Order.h"

/**
 * @brief Construct a new Order:: Order object
 *
 */
Order::Order() : customer(nullptr), paymentMethod(nullptr) {}


Order::Order(Customer *customer, Staff *staff): customer(customer),staff(staff){}
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

	paymentMethod->purchase(customer, plants, staff);
}

/**
 * @brief add a plant to the order
 *
 * @param p
 */
void Order::addPlant(Plant *p)
{
	if (!p)
		return;

	try
	{
		++plants.at(p);
	}
	catch (std::out_of_range err)
	{
		plants[p] = 1;
	}
}

/**
 * @brief remove a plant from the order
 *
 * @param p
 */
void Order::removePlant(Plant *p)
{
	--plants[p];

	if (plants[p] < 1)
		plants.erase(p);
}

/**
 * @brief sets the staff member variable
 * 
 * @param s 
 */
void Order::setStaff(Staff *s){
	if(!s) return;

	staff = s;
}

/**
 * @brief sets the customer variable
 * 
 * @param c 
 */
void Order::setCustomer(Customer *c){
	if(!c) return;

	customer = c;
}