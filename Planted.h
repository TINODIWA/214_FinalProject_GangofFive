/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANTED_H_
#define PLANTED_H_

#include "PlantState.h"

class Planted : public PlantState {
 public:
  Planted();
  Planted(const PlantState& other);
  void handleChange();
};

#endif  // PLANTED_H_
