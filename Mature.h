/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef MATURE_H_
#define MATURE_H_

#include "PlantState.h"

class Mature : public PlantState {
 public:
  Mature();
  ~Mature();
  Mature(const PlantState& other);
  PlantState* clone();
  void handleChange();
};

#endif  // MATURE_H_
