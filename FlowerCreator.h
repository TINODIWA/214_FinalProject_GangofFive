#ifndef FLOWERCREATOR_H
#define FLOWERCREATOR_H

#include "PlantCreator.h"
#include "Plant.h"
class FlowerCreator : PlantCreator
{

public:
	Plant *produce();
};

#endif
