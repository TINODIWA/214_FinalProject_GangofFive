/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef GARDENPLOT_H_
#define GARDENPLOT_H_

#include <iostream>
#include <string>
#include <map>

#include "Iterator.h"
#include "Director.h"
#include "Builder.h"
#include "CropBuilder.h"
#include "PlantBuilder.h"
#include "Garden.h"

using namespace std;

class GardenPlot {
 private:
  Garden* garden;

 public:
  GardenPlot();
  GardenPlot(string filename);
  ~GardenPlot();

  map<string,int> viewAll();
  map<string,int> viewAvailable();
  void transpire(int decreasedLevel);
  vector<Garden*> get(string name, int num);
  Garden* get(string name);
  string print();
  int size();
  int numCrops();
  Iterator* access();

};
#endif  // GARDENPLOT_H_
