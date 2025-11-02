#ifndef MEDIUM_H_
#define MEDIUM_H_

#include "PlantCare.h"

class Medium : public PlantCare {
 public:
  Medium();
  Medium(const Medium& other);
  ~Medium() ;

  PlantCare* clone();

  int changeAmount(int curr, int target) override;
};

#endif
