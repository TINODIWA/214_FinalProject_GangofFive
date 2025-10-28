#ifndef PLANTCARE_H
#define PLANTCARE_H

#include "FertiliseStrategy.h"
#include "SunStrategy.h"
#include "WaterStrategy.h"

class PlantCare {
   private:
    WaterStrategy* water;
    SunStrategy* sun;
    FertiliseStrategy* fertilise;

   public:
    PlantCare(const PlantCare& other);

    int waterAlgorithm();

    int sunAlgorithm();

    int fertiliseAlgorithm();

    PlantCare();
};

#endif
