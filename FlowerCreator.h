/**
 * @copyright Copyright (c) 2025
 *
 */
#ifndef FLOWERCREATOR_H_
#define FLOWERCREATOR_H_

#include "Flower.h"
#include "PlantCreator.h"

class PlantInfo;

class FlowerCreator : public PlantCreator {
 public:
  FlowerCreator();
  ~FlowerCreator();
  FlowerCreator(const PlantCreator* other);
  Plant* produce(const PlantInfo& info);
  PlantCreator* clone();
};

#endif  // FLOWERCREATOR_H_
