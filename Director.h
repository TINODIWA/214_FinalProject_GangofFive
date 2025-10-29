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
#include "PlantInfo.h"

using namespace std;

class Director {
 private:
  CropBuilder* cropBuilder;
  map<string, vector<PlantInfo>> plants;
  vector<string> plantTypes;

 public:
  Director();
  ~Director();
  explicit Director(CropBuilder* p);
  void setBuilder(CropBuilder* p);
  Plant* construct(string filename);
  void parse(string filename);
};

#endif  // DIRECTOR_H_
