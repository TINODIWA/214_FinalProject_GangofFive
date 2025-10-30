/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "Builder.h"
#include "Crop.h"
#include "CropBuilder.h"

using namespace std;

class Director {
 private:
  Builder* cropBuilder;

 public:
  Director();
  ~Director();
  Director(CropBuilder* p);
  void setBuilder(Builder* p);
  Plant* construct(string filename);
  void parse(string filename);
};

#endif  // DIRECTOR_H_
