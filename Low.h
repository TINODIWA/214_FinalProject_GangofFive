/**
 * @file Low.h
 * @brief Low plant care level
 */

#ifndef LOW_H_
#define LOW_H_

#include "PlantCare.h"

class Low : public PlantCare {
 public:
  Low();
  ~Low() override;
  int changeAmount() override;
  
  //   Low(const Low& other);
};

#endif
