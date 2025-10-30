/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef DYING_H_
#define DYING_H_
#include "PlantState.h"
class Dying : PlantState {
 public:
  Dying();

  Dying(const PlantState& other);

  void handleChange();
};

#endif  // DYING_H_
