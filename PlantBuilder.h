/**
 * @copyright Copyright (c) 2025
 */

#ifndef PLANTBUILDER_H_
#define PLANTBUILDER_H_

#include "Builder.h"
#include "Plant.h"
#include "Garden.h"

class PlantBuilder : public Builder {
 private:
  Plant* p;

 public:
  PlantBuilder();
  ~PlantBuilder();
  PlantBuilder(const PlantBuilder* other);
  Builder* setName(string name);
  Builder* setType(string type);
  Builder* setWater(int water);
  Builder* setSun(int sun);
  Builder* setFertiliser(int fertiliser);
  Builder* setAttention(int attention);
  Builder* setWaterCare(PlantCare* water);
  Builder* setSunCare(PlantCare* sun);
  Builder* setFertiliserCare(PlantCare* fertiliser);
  Builder* setDays(vector<int> days);
  Builder* setPrice(int price);
  Plant* build();
  PlantBuilder* clone();
  void reset();
};

#endif  // PLANTBUILDER_H_
