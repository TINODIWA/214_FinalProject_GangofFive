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
 public:
  Garden();
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
  virtual Garden* get(string name);
  virtual bool operator==(string name);
  virtual void changeState(int days);
};

#endif  // GARDEN_H_
