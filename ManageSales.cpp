/**
 * @file ManageSales.cpp
 * @author Nathan Chisadza
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "ManageSales.h"

/**
 * @brief Construct a new ManageSales object for Command
 * @param s Staff being appointed to fulfill the command
 * @param m Staff coordination pointer for the command to go to correct ConcreteMediator
 */
ManageSales::ManageSales(Staff *s, StaffCo_ordination *m) : Command(s, m) {}

/**
 * @brief Execute the Manage Sales command
 * @return void
 */
void ManageSales::execute() {
    mediator->sendMessage("Managing sales", appointed, "ManageSales");
}
