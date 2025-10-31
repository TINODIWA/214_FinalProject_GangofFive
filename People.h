/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PEOPLE_H_
#define PEOPLE_H_

#include "Nursery.h"
#include <string>
#include <iostream>

using namespace std;
class People {
 private:
  string name;
  Nursery* nursery;

 public:
  People(Nursery* n, string name);
  People();
  People(const People* other);
  void send(string m, Nursery* s, string type);
  void receive(string m, People* from, Nursery* n);
  string getName() const;
};

#endif  // PEOPLE_H_
