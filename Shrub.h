#ifndef SHRUB_H
#define SHRUB_H

#include "Plant.h"

class Shrub : public Plant
{

public:
	Shrub();
	Shrub(PlantInfo info);
	Shrub(const Plant &other);
	~Shrub();
	Plant *clone();
};

#endif
