/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef BUILDPLANT_H_
#define BUILDPLANT_H_

#include "Plant.h"
#include "Garden.h"

class BuildPlant {
 public:
  BuildPlant();
  virtual ~BuildPlant();
  virtual BuildPlant* setName(string name) = 0;
  virtual BuildPlant* setType(string type) = 0;
  virtual BuildPlant* setWater(int water) = 0;
  virtual BuildPlant* setSun(int sun) = 0;
  virtual BuildPlant* setFertiliser(int fertiliser) = 0;
  virtual BuildPlant* setAttention(int attention) = 0;
  virtual BuildPlant* setWaterCare(char level) = 0;
  virtual BuildPlant* setSunCare(char level) = 0;
  virtual BuildPlant* setFertiliserCare(char level) = 0;
  virtual BuildPlant* setDays(vector<int> days) = 0;
  virtual BuildPlant* setPrice(float price) = 0;
  virtual Plant* build() = 0;
  virtual BuildPlant* clone() = 0;
  virtual void reset() = 0;
};
#endif  // BUILDPLANT_H_
