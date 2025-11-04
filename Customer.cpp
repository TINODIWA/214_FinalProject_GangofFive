
/**
 * @file Customer.cpp
 * @author Unathi Tshakalisa
 * @brief Implementation of the Customer class, which manages customer interactions and order history in the nursery
 * system
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Customer.h"
#include "CustomerCare.h"
#include "Order.h"

/**
 * @brief Construct a new Customer object
 * @param name Name of the customer
 */
Customer::Customer(string name) : People(NULL, name) {
  // req = Request("Enter");
  // order = NULL;
}

/**
 * @brief Destroy the Customer object and free its order history
 */
Customer::~Customer() {
  for (Order* o : orderHistory) {
    if (o) {
      delete o;
      o = NULL;
    }
  }
}  // should probably deletee their orders

/**
 * @brief Copy constructor for Customer
 * @param other Pointer to another Customer to copy from
 */
Customer::Customer(const Customer* other) {
  // if (other)
  // this->order = new Order(*other->order);
}

/**
 * @brief Make a request on behalf of the customer
 * @param req The request to send
 */
void Customer::makeReq(Request req) {
  Nursery* n = getNursery();
  if (n) {
    if (CustomerCare* cc = dynamic_cast<CustomerCare*>(n)) {
      cc->notify(req, this);
    } else {
      send(req.getRequest(), n, "CustomerRequest");
    }
  } else {
    std::cout << "No customer care mediator set for customer: " << getName() << std::endl;
  }
}

/**
 * @brief Add an order to the customer's order history
 * @param order Pointer to the Order to add
 */
void Customer::addOrder(Order* order) {
  this->orderHistory.push_back(order);
}

/**
 * @brief Get the customer's order history
 * @return Vector of pointers to the customer's previous orders
 */
vector<Order*> Customer::getOrderHistory() {
  return this->orderHistory;
}

/**
 * @brief Receive a message from another People object
 * @param m Message string
 * @param from Pointer to the sender
 * @param group Pointer to the nursery/mediator group
 * @param type Type of the message
 * @return void
 */
void Customer::receive(string m, People* from, Nursery* group, string type) {
  cout << "\nMessage sent from " << from->getName() << ":\t" << m << endl;
}
