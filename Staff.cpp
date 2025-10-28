#include "Staff.h"

void Staff::handlePlant(Plant *p)
{
	// TODO - implement Staff::handlePlant
	//	throw "Not yet implemented";
}

void Staff::handleCustomer(Request *req)
{
	// TODO - implement Staff::handleCustomer
	// throw "Not yet implemented";
}

Staff::Staff() : People()
{
	// TODO - implement Staff::Staff
	// throw "Not yet implemented";
}

Staff::Staff(const Staff*other) : People(*other)
{
	if (other)
	{
		this->name = other->name;
		this->level = other->level;
		this->successor = new Staff(*other->successor);

		vector<string>::const_iterator it = other->responsibilities.begin();

		while (it != other->responsibilities.end())
		{
			responsibilities.push_back(*it);
		}
	}
}

string Staff::JobDesc()
{
	// TODO - implement Staff::JobDesc
	// throw "Not yet implemented";
}

string Staff::getType()
{
	// TODO - implement Staff::getType
	// throw "Not yet implemented";
}
