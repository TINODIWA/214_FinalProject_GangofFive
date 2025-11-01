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
  string level;
  vector<string> responsibilities;
  Staff* successor;

 public:
  Staff(string name);
  Staff(const Staff* other);
  void handlePlant(Plant* p);
  void handleCustomer(Request* req);
  string JobDesc();
  string getType();
};

#endif  // STAFF_H_
