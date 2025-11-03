/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CROP_H_
#define CROP_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Garden.h"
#include "Iterator.h"
#include "Plant.h"

using namespace std;

class Crop : public Garden {
 private:
  vector<Garden*> plants;
  struct itImpl;
  itImpl* pImpl;

 public:
  Crop();
  ~Crop();
  Crop(const Crop& other);
  void add(Garden* p);
  Garden* clone();
  string print();
  void removeDeadPlants();
  Iterator* createIterator();
  map<string, int> summary(map<string, int>& sum);
  bool done();
  Garden* next();
  vector<Garden*> get(string name, int num);
  Garden* get(string name);
};

#endif  // CROP_H_
