#ifndef SHRUB_H
#define SHRUB_H

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

#endif
