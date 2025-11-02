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

#include "Sales.h"
#include <iostream>

Sales::Sales(Staff* s) : Roles(s->getNursery(), s->getName(), s) {}

Sales::~Sales() {}

string Sales::getType() {
  return Roles::getType() + ": Sales";
}

/**
 * @brief Get the job description for this staff role.
 */
std::string Sales::jobDesc() {
  return Roles::jobDesc() + "\nAdditionally, Sales staff are responsible for assisting customers with their purchases.";
}

void Sales::handleCustomer(Request* req) {
  if(req != NULL && req->getRequest() == "Purchase"){
    // setColleague(this, ?)
  }
  else{
    cout << "Sales is passing on this request." << endl;
    Staff::handleCustomer(req);
  }
}

void Sales::handlePlant(Plant* p) {

}

void Sales::receive(string m, People* from, Nursery* group, string type) {
  if(!(from || group)) return;
  
}
