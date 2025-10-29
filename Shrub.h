/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef SHRUB_H_
#define SHRUB_H_

#include <iomanip>
#include "Plant.h"

class Shrub : public Plant {
   public:
    Shrub();
    Shrub(const PlantInfo &info);
    Shrub(const Plant &other);
    void addPlant(Plant *p);
    virtual ~Shrub();
    Plant *clone();

    void print();
};

#endif  // SHRUB_H_
