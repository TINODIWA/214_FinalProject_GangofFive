/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef GROWING_H_
#define GROWING_H_
#include "PlantState.h"

#include "PlantState.h"
class Growing : public PlantState {
 public:
  Growing();
  ~Growing();
  Growing(const PlantState& other);
  PlantState* clone();
  void handleChange();
  string getState();
};

#endif  // GROWING_H_
