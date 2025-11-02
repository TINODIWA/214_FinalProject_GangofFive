/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ROLES_H_
#define ROLES_H_
#include <string>
#include <vector>

class Roles : Staff {
 public:
  vector<Staff*> staff;

  Roles();

  string jobDesc();

  string getType();
};

#endif  // ROLES_H_
