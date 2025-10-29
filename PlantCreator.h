/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANTCREATOR_H_
#define PLANTCREATOR_H_

#include "Plant.h"
#include <iostream>

class PlantCreator {
 protected:
  virtual Plant* produce(const PlantInfo& info) = 0;

 public:
  PlantCreator();
  PlantCreator(const PlantCreator* other);
  virtual ~PlantCreator();
  Plant* create(const PlantInfo& plantInfo);
  virtual PlantCreator* clone() = 0;
};

#endif  // PLANTCREATOR_H_
