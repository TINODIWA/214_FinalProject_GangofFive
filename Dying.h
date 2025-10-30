/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef DYING_H_
#define DYING_H_

#include "PlantState.h"

class Dying : public PlantState {
 public:
  Dying();
  ~Dying();
  Dying(const PlantState& other);
  PlantState* clone();
  void handleChange();
};

#endif  // DYING_H_
