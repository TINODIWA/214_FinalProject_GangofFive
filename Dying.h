/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef DYING_H_
#define DYING_H_

#include "PlantState.h"
class Plant;

class Dying : public PlantState {
 private:
  PlantState* prev;

 public:
  Dying();
  ~Dying();
  Dying(const PlantState& other);
  void handleChange(Plant* p);
  string getState();
  void setPrev(PlantState* prev);
};

#endif  // DYING_H_
