/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef BUILDER_H_
#define BUILDER_H_

#include <iostream>
#include <string>
#include <vector>

class Garden;
class PlantCare;
class Staff;
class Plant;

using namespace std;

class Builder {
 public:
  Builder();
  virtual ~Builder();

  virtual Builder* clone() = 0;
  virtual void reset() = 0;
};

#endif  // BUILDER_H_
