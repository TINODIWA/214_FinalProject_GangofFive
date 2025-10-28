#include "Nursery.h"
#include "Staff.h"
#include "Customer.h"

Nursery::Nursery()
{
	// TODO - implement Nursery::Nursery
	// throw "Not yet implemented";
}

Nursery::~Nursery()
{
}

Nursery::Nursery(const Nursery &other)
{
	vector<vector<Plant *>>::const_iterator otherPlants = (other.plants).begin();
	vector<Customer *>::const_iterator otherCustomer = (other.customers).begin();
	vector<Staff *>::const_iterator otherStaff = (other.staff).begin();

	while (otherPlants != other.plants.end())
	{
		vector<Plant *>::const_iterator it = (*otherPlants).begin();
		vector<Plant *> temp;

		while (it != (*otherPlants).end())
		{
			temp.push_back((*it)->clone());
		}
		plants.push_back(temp);
	}

	// while(otherCustomer != other.customers.end())
	// 	customers.push_back(new Customer(*otherCustomer))
}

void Nursery::addPlant(Plant *p)
{
	// TODO - implement Nursery::addPlant
	// throw "Not yet implemented";
}

void Nursery::removePlant(Plant *p)
{
	// TODO - implement Nursery::removePlant
	// throw "Not yet implemented";
}

void Nursery::start(bool sim)
{
	// TODO - implement Nursery::start
	// throw "Not yet implemented";
}

void Nursery::addStaff(Staff *s)
{
	// TODO - implement Nursery::addStaff
	// throw "Not yet implemented";
}

void Nursery::removeStaff(Staff *s)
{
	// TODO - implement Nursery::removeStaff
	// throw "Not yet implemented";
}

void Nursery::notify()
{
	// TODO - implement Nursery::notify
	// throw "Not yet implemented";
}
