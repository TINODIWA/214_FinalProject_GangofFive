/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANTED_H_
#define PLANTED_H_

#include "PlantState.h"
class Plant;

class Planted : public PlantState {
 public:
  Planted();
  ~Planted();
  Planted(const PlantState& other);
  void handleChange(Plant* p,int day);
  string getState();
};

#endif  // PLANTED_H_
