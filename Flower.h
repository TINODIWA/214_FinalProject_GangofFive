/**
 * @copyright Copyright (c) 2025
 *
 */
#ifndef FLOWER_H_
#define FLOWER_H_

#include "Plant.h"
#include <iomanip>

class Flower : public Plant {
 public:
  Flower();
  explicit Flower(const PlantInfo& info);
  explicit Flower(const Plant& other);
  void addPlant(Plant* p);
  ~Flower();
  Plant* clone();

  void print();
};

#endif  // FLOWER_H_
