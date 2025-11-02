/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef GARDEN_H_
#define GARDEN_H_

#include <iostream>
#include <map>
#include <vector>

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
  virtual map<string,int> summary(map<string,int>& sum);
  virtual string getState();
  virtual string advice();
  virtual  vector<Garden*> get(string name, int num);
  bool operator==(int id);
};

#endif  // GARDEN_H_
