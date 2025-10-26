#ifndef SHRUBCREATOR_H
#define SHRUBCREATOR_H

#include "PlantCreator.h"
#include "Shrub.h"

class PlantInfo;

class ShrubCreator : public  PlantCreator
{

public:
	ShrubCreator();
	~ShrubCreator();
	Plant *produce(const PlantInfo &info);
};

#endif
