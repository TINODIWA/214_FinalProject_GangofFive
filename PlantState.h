/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANTSTATE_H_
#define PLANTSTATE_H_

#include "PlantState.h"

class PlantState {
 public:
  PlantState();
  virtual ~PlantState();
  PlantState(const PlantState& other);
  virtual void handleChange() = 0;
  virtual PlantState* clone() = 0;
};

#endif  // PLANTSTATE_H_
