/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef MATURE_H
#define MATURE_H
#include "PlantState.h"
#include <vector>

class Plant;

class Mature : public PlantState {
 public:
  Mature();
  ~Mature();
  Mature(const PlantState& other);
  void handleChange(Plant* p);
  string getState();
  PlantState* clone();
};

#endif  // MATURE_H_
