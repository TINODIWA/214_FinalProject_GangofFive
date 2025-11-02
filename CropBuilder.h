/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CROPBUILDER_H_
#define CROPBUILDER_H_

#include <string>

#include "Builder.h"
#include "Crop.h"
#include "Garden.h"
#include "PlantCare.h"
#include "Staff.h"

class PlantInfo;

class CropBuilder : public Builder {
 private:
  Garden* root;
  Garden* currCrop;

 public:
  CropBuilder();
  ~CropBuilder();
  CropBuilder(const CropBuilder* other);
  void add();
  void add(Garden* p);
  Garden* getCrop();
  CropBuilder* clone();
  void reset();
};

#endif  // CROPBUILDER_H_
