/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef DEAD_H_
#define DEAD_H_

#include "PlantState.h"

class Dead : public PlantState {
 public:
  Dead();
  ~Dead();
  Dead(const PlantState& other);
  void handleChange();
  string getState();
  PlantState* clone();
};

#endif  // DEAD_H_
