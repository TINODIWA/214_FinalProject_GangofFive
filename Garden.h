/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef GARDEN_H_
#define GARDEN_H_

#include <iostream>
#include <map>
#include "Iterator.h"

using namespace std;

class Garden {
 protected:
  int id;

 public:
  Garden();
  Garden(int id);
  virtual ~Garden();
  virtual Garden* clone() = 0;
  virtual void add(Garden* p);
  virtual string print() = 0;
  virtual Iterator* createIterator();
  virtual void transpire(int decreasedLevel);
  virtual string summary();
  virtual string getState();
  virtual string advice();
  virtual Garden* get(int id);
  bool operator==(int id);
};

#endif  // GARDEN_H_
