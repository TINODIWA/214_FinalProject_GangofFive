#include <iostream>
#include "Request.h"
#include "Admin.h"


Admin::Admin() : Roles() {

}

Admin::~Admin() {

}

// staff.getjobdesc + handling sales



std::string Admin::getType() {
	return "Admin";
}

std::string Admin::jobDesc() {
	return "Admin staff responsible for administration and inventory.";
}


void Admin::updateInventory() {
    std::cout << "Admin is checking inventory records" << std::endl;
    //code
    std::cout << "Inventory updated by Admin." << std::endl;
}

void Admin::handleCustomer(Request* req) {
    if (req) {
        std::cout << "Admin staff handled request: " << req->getRequest() << std::endl;
    } else if (successor) {
        successor->handleCustomer(req);
    } else {
        std::cout << "No staff could handle the request." << std::endl;
    }
}

void Admin::handlePlant(Plant* p) {
	//doesnt handle plants here chief
}
