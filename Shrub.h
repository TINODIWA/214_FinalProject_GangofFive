#ifndef SHRUB_H
#define SHRUB_H

#include "Plant.h"

class Shrub : public Plant
{

public:
	Shrub();
	Shrub(const PlantInfo &info);
	Shrub(const Plant &other);
	void addPlant(const PlantInfo &p);
	virtual ~Shrub();
	Plant *clone();
};

#endif
