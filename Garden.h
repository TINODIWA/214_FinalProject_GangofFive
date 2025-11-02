/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef GARDEN_H_
#define GARDEN_H_

#include <iostream>
#include "Iterator.h"

using namespace std;

class Garden {
 public:
  Garden();
  virtual ~Garden();
  virtual Garden* clone() = 0;
  virtual void add(Garden* p);
  virtual string print() = 0;
  virtual Iterator* createIterator();
  virtual void transpire(int decreasedLevel);
  virtual string summary();
};

#endif  // GARDEN_H_
