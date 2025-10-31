/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef STAFF_H_
#define STAFF_H_

#include <string>
#include <vector>

#include "People.h"
#include "Request.h"
class Plant;
class Staff : public People {
 private:
  string name;
  string level;
  vector<string> responsibilities;
  Staff* successor;

 public:
  void handlePlant(Plant* p);
  void handleCustomer(Request* req);
  Staff();
  Staff(const Staff* other);
  virtual ~Staff();
  string jobDesc();
  string getType();
  void setNext(Staff* successor);
};

#endif  // STAFF_H_
