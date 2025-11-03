/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANTSTATE_H_
#define PLANTSTATE_H_

#include "PlantState.h"
#include <string>
class Plant;

using namespace std;

class PlantState {
 public:
  PlantState();
  PlantState(const PlantState& other);
  virtual ~PlantState();
  bool dying(Plant*p);
  virtual void handleChange(Plant* p,int day) = 0;
  virtual string getState() = 0;
};

#endif  // PLANTSTATE_H_
