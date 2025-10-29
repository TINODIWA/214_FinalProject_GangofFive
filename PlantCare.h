/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANTCARE_H_
#define PLANTCARE_H_

#include "FertiliseStrategy.h"
#include "SunStrategy.h"
#include "WaterStrategy.h"

class PlantCare {
 private:
  WaterStrategy* water;
  SunStrategy* sun;
  FertiliseStrategy* fertilise;

 public:
  PlantCare(const PlantCare& other);

  int waterAlgorithm();

  int sunAlgorithm();

  int fertiliseAlgorithm();

  PlantCare();
};

#endif  // PLANTCARE_H_
