#include "Staff.h"



Staff::Staff() : People()
{
	successor = nullptr;
}


Staff::~Staff(){

}

void Staff::setSuccessor(Staff *succ)
{
	this->successor = succ;
}

Staff::Staff(const Staff* other) : People(*other)
{
	// if (other)
	// {
	// 	this->name = other->name;
	// 	this->level = other->level;
	// 	this->successor = nullptr; // Cannot copy abstract Staff
	// 	vector<string>::const_iterator it = other->responsibilities.begin();
	// 	while (it != other->responsibilities.end())
	// 	{
	// 		responsibilities.push_back(*it);
	// 		++it;
	// 	}
	// }
}


