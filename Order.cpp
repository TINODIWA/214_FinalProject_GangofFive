/**
 * @file Order.cpp
 * @author Unathi Tshakalisa, Swelihle Makhathini
 * @brief Implementation of the Order class which manages customer orders including plant selections and payment processing
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Order.h"

/**
 * @brief Construct a new Order:: Order object
 *
 */
Order::Order() : customer(nullptr), paymentMethod(nullptr) {}

Order::~Order(){
    clearOrder();
    delete paymentMethod;
    paymentMethod = nullptr;
}

/**
 * @brief Copy constructor for Order class
 * @param other The Order object to copy from
 */
Order::Order(const Order &other){

}

/**
 * @brief Construct a new Order with customer and staff
 * @param customer Pointer to the customer placing the order
 * @param staff Pointer to the staff member handling the order
 */
Order::Order(Customer *customer, Staff *staff): customer(customer),staff(staff){}
/**
 * @brief purchase and order
 *
 */
void Order::purchase(int day)
{
	cout << "Please select a payment method:\n";

	string choice;
	bool valid = false;

	while (!valid)
	{
		cout << "** Please enter the correct number from below**\n";
		cout << "1. EFT\n";
		cout << "2. Card\n";
		cout << "3. Cash\n";

		cout << "Payment Method: ";
		cin >> choice;

		if (choice == "")
			continue;
		if (choice == "1")
		{
			paymentMethod = new EFT();
			valid = true;
		}
		else if (choice == "2")
		{
			paymentMethod = new Card();
			valid = true;
		}
		else if (choice == "3")
		{
			paymentMethod = new Cash();
			valid = true;
		}
		else
		{
			cout << "Invalid payment method, please try again.\n";
		}
	}

	this->receipt = paymentMethod->purchase(customer, plants, staff);
	cout<<"\nYour receipt: \n\t"<<receipt<<"\n\n"<<endl;
	this->purchaseDate = day;
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

/**
 * @brief Prints the details of a previously made order
 * @return string containing the receipt and purchase date
 */
string Order::printOldOrder(){
	stringstream ss ;
	ss<< this->receipt << "\tPurchased on day: "<<this->purchaseDate;
	return ss.str();
}

/**
 * @brief Get the map of plants and their quantities in the order
 * @return map<Plant *, int> Map of plant pointers to their quantities
 */
map<Plant *, int> Order::getPlants(){
	return plants;
}

/**
 * @brief Clears all plants from the order
 */
void Order::clearOrder() {
	for (auto& pair : plants) {
        delete pair.first;  
    }
    plants.clear();
}
