#ifndef SHRUBCREATOR_H
#define SHRUBCREATOR_H

#include "PlantCreator.h"
#include "Shrub.h"

class PlantInfo;

class ShrubCreator : PlantCreator {

public:
	Plant* produce(PlantInfo* info);
};

#endif
