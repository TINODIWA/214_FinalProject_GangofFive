/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef SHRUBCREATOR_H_
#define SHRUBCREATOR_H_

#include "PlantCreator.h"
#include "Shrub.h"

class PlantInfo;

class ShrubCreator : public PlantCreator {
 public:
  ShrubCreator();
  ~ShrubCreator();
  ShrubCreator(const PlantCreator* other);
  Plant* produce(const PlantInfo& info);
  PlantCreator* clone();
};

#endif  // SHRUBCREATOR_H_
