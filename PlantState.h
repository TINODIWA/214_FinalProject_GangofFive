/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANTSTATE_H_
#define PLANTSTATE_H_

#include "PlantState.h"
#include <string>

using namespace std;

class PlantState {
 public:
  PlantState();
  PlantState(const PlantState& other);
  virtual ~PlantState();

  virtual void handleChange() = 0;
  virtual string getState() = 0;
  virtual PlantState* clone() = 0;
};

#endif  // PLANTSTATE_H_
