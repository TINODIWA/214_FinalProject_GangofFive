#include "Roles.h"

/**
 * @brief Construct a new Roles object.
 */
Roles::Roles() : Staff() {
	//calls base class staff to initialize inherited part of roles
}

/**
 * @brief Destroy the Roles object.
 */
Roles::~Roles() {
	//niks
}

// std::string Roles::jobDesc() {
//     return "General role for staff.";
// }

// std::string Roles::getType() {
//     return "Roles";
// }
