/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CROPBUILDER_H_
#define CROPBUILDER_H_

#include <string>

#include "Builder.h"
#include "Crop.h"
#include "PlantCare.h"
#include "Staff.h"

class PlantInfo;

class CropBuilder : public Builder {
 private:
  Plant* root;
  Plant* currCrop;

 public:
  CropBuilder();
  ~CropBuilder();
  CropBuilder(const CropBuilder* other);
  void addCrop(string name);
  void addPlant(const Plant* p);
  Builder* clone();
  void reset();
  Plant* getCrop();
};

#endif  // CROPBUILDER_H_
