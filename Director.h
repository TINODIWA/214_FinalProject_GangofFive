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
#include "Garden.h"
#include "CropBuilder.h"
#include "PlantBuilder.h"

using namespace std;

class Director {
 private:
  CropBuilder* cropBuilder;
  PlantBuilder* plantBuilder;

 public:
  Director();
  ~Director();
  Director(CropBuilder* c, PlantBuilder* p);
  void setBuilder(CropBuilder* c);
  void setBuilder(PlantBuilder* p);
  Garden* construct(string filename);
  void parse(string filename);
  vector<string> split(const string str, char delim);
};

#endif  // DIRECTOR_H_
