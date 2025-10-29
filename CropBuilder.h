/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CROPBUILDER_H_
#define CROPBUILDER_H_

#include <string>
#include <vector>

#include "Builder.h"
#include "Crop.h"
#include "FlowerCreator.h"
#include "PlantCare.h"
#include "PlantCreator.h"
#include "ShrubCreator.h"
#include "Staff.h"
#include "TreeCreator.h"

class PlantInfo;

class CropBuilder : public Builder {
 private:
  Plant* root;
  Plant* currCrop;
  map<string, PlantCreator*> factories;

 public:
  CropBuilder();
  ~CropBuilder();
  CropBuilder(const CropBuilder* other);
  CropBuilder(map<string, PlantCreator*> factories);
  void addCrop(string name);
  void addPlant(const PlantInfo& p);
  void setFactories(map<string, PlantCreator*> factories);
  void addFactory(std::string type, PlantCreator* factory);
  void reset();
  Plant* getCrop();
};

#endif  // CROPBUILDER_H_
