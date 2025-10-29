/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef SHRUB_H_
#define SHRUB_H_

#include "Plant.h"
#include <iomanip>

class Shrub : public Plant {
 public:
  Shrub();
  explicit Shrub(const PlantInfo& info);
  explicit Shrub(const Plant& other);
  void addPlant(Plant* p);
  virtual ~Shrub();
  Plant* clone();

  void print();
};

#endif  // SHRUB_H_
