#ifndef FLOWERCREATOR_H
#define FLOWERCREATOR_H

#include "Flower.h"
#include "PlantCreator.h"

class PlantInfo;

class FlowerCreator : public PlantCreator {
   public:
    FlowerCreator();
    ~FlowerCreator();
    FlowerCreator(const PlantCreator* other);
    Plant* produce(const PlantInfo& info);
    PlantCreator* clone();
};

#endif
