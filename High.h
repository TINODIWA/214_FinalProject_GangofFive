#ifndef HIGH_H_
#define HIGH_H_

#include "PlantCare.h"

class High : public PlantCare {
 public:
  High();
  High(const High& other);
  ~High() override;

  int changeAmount(int curr, int target) override;
}; 

#endif
