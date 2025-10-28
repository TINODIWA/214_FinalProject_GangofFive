#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

#include <iostream>
#include "Plant.h"

class PlantCreator {
   protected:
    virtual Plant* produce(const PlantInfo& info) = 0;

   public:
    PlantCreator();
    PlantCreator(const PlantCreator* other);
    virtual ~PlantCreator();
    Plant* create(const PlantInfo& plantInfo);
    virtual PlantCreator* clone() = 0;
};

#endif
