#ifndef HIGH_H_
#define HIGH_H_

#include "PlantCare.h"

class High : public PlantCare {
 public:
  High();
  High(const High& other);
  ~High() ;
  PlantCare* clone();

  int changeAmount(int currWL, int WL) override;
};

#endif
