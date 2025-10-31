#include <iostream>
#include <vector>
#include <algorithm>
#include "Request.h"
#include "Sales.h"


Sales::Sales() : Roles() {
}

Sales::~Sales(){

}

std::string Sales::getType() {
	return "Sales";
}

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

