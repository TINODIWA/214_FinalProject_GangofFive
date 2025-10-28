#ifndef SHRUBCREATOR_H
#define SHRUBCREATOR_H

#include "PlantCreator.h"
#include "Shrub.h"

class PlantInfo;

class ShrubCreator : public PlantCreator
{

public:
	ShrubCreator();
	~ShrubCreator();
	ShrubCreator(const PlantCreator *other);
	Plant *produce(const PlantInfo &info);
	PlantCreator* clone();
};

#endif
