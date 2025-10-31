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

class CropIterator;

using namespace std;

class Crop : public Garden {
 public:
  std::vector<Garden*> plants;

  Crop();
  ~Crop();
  Crop(const Crop& other);
  void add(Garden* p);
  Garden* clone();
  void print();
  CropIterator* createIterator();
};

#endif  // CROP_H_
