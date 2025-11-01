#ifndef MEDIUM_H_
#define MEDIUM_H_

#include "PlantCare.h"

class Medium : public PlantCare {
 public:
  Medium();
  Medium(const Medium& other);
  ~Medium() override;

  PlantCare* clone();

  int changeAmount(int currWL, int WL) override;
};

#endif
