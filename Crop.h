/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CROP_H_
#define CROP_H_

#include <iostream>
#include <string>
#include <vector>

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
  void print();
  void removeDeadPlants();
  Iterator* createIterator();
  

  bool done();
  Garden* next();
};

#endif  // CROP_H_
