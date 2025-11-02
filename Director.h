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

#include "Garden.h"
#include "CropBuilder.h"
#include "PlantBuilder.h"
#include "BuildPlant.h"

using namespace std;

class Director {
 private:
  Builder* cropBuilder;
  BuildPlant* plantBuilder;

 public:
  Director();
  ~Director();
  Director(Builder* c, BuildPlant* p);
  void setBuilder(Builder* c);
  void setBuilder(BuildPlant* p);
  Garden* construct(string filename);
  void parse(string filename);
  vector<string> split(const string str, char delim);
};

#endif  // DIRECTOR_H_
