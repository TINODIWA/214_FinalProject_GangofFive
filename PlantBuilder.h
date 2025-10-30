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
  PlantBuilder* setName(string name);
  PlantBuilder* setType(string type);
  PlantBuilder* setWater(int water);
  PlantBuilder* setSun(int sun);
  PlantBuilder* setFertiliser(int fertiliser);
  PlantBuilder* setAttention(int attention);
  PlantBuilder* setWaterCare(PlantCare* water);
  PlantBuilder* setSunCare(PlantCare* sun);
  PlantBuilder* setFertiliserCare(PlantCare* fertiliser);
  PlantBuilder* setDays(vector<int> days);
  PlantBuilder* setPrice(int price);
  Plant* build();
  PlantBuilder* clone();
  void reset();
};

#endif  // PLANTBUILDER_H_
