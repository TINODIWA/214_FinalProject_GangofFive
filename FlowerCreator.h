#ifndef FLOWERCREATOR_H
#define FLOWERCREATOR_H

#include "PlantCreator.h"
#include "Flower.h"	

class PlantInfo;

class FlowerCreator : public PlantCreator
{

public:
	FlowerCreator();
	~FlowerCreator();
	Plant *produce(const PlantInfo& info);
};

#endif
