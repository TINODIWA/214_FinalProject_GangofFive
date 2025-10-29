/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ORDER_H_
#define ORDER_H_

#include "Customer.h"
#include "Plant.h"
#include <vector>

using namespace std;

class Order {
 private:
  vector<Plant*> plants;
  Customer* customer;

 public:
  Order();
  ~Order();
  Order(const Order& other);

 private:
  void prepare();
  void payment();
  void package();

 public:
  void addPlant(Plant* p);

  void removePlant(Plant* p);

  void purchase();
};

#endif  // ORDER_H_
