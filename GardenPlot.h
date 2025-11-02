/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef GARDENPLOT_H_
#define GARDENPLOT_H_

#include <iostream>
#include <string>

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

  string viewAll();
  string viewAvailable();
  void transpire(int decreasedLevel);


};
#endif  // GARDENPLOT_H_
