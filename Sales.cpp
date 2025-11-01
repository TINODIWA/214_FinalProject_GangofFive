/**
 * @file Sales.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "Request.h"
#include "Sales.h"

/**
 * @brief Construct a new Sales object.
 */
Sales::Sales() : Roles() {
}

/**
 * @brief Destroy the Sales object.
 */
Sales::~Sales(){

}

/**
 * @brief Get the staff type for this object.
 */
std::string Sales::getType() {
	return "Sales";
}

/**
 * @brief Get the job description for this staff role.
 */
std::string Sales::jobDesc() {
	return "Sales staff responsible for handling sales and customer requests.";
}


void Sales::handleSales() {
    std::cout << "Sales staff is processing a sale..." << std::endl;
    //sales logic here???????
    std::cout << "Sale completed successfully." << std::endl;
}


void Sales::handleCustomer(Request* req) {
	if (req) {
		std::cout << "Sales staff handled request: " << req->getRequest() << std::endl;
	} else if (successor) {
		successor->handleCustomer(req);
	} else {
		std::cout << "No staff could handle the request." << std::endl;
	}
}

void Sales::handlePlant(Plant* p) {
    //doesnt handle plants chief
}

