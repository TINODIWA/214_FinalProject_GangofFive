/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef GROWING_H_
#define GROWING_H_
#include "PlantState.h"

class Plant;

class Growing : public PlantState {
 public:
  Growing();
  ~Growing();
  Growing(const PlantState& other);
  void handleChange(Plant* p);
  string getState();
};

#endif  // GROWING_H_
