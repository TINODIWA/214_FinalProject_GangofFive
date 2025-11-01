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
  ~Staff();
  virtual void update(Plant* p);
  void handlePlant(Plant* p);
  void handleCustomer(Request* req);
  string JobDesc();
  string getType();
  string getLevel() const;
  vector<string> getResponsibilities() const;
  bool operator==(const Staff& other) const;
};

#endif  // STAFF_H_
