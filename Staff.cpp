/**
 * @file Staff.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Staff.h"


/**
 * @brief Construct a new Staff object.
 */
Staff::Staff() : People() {
	successor = nullptr;
}

/**
 * @brief Destroy the Staff object.
 */
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


