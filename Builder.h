#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>

#include "Crop.h"
#include "Tree.h"
#include "Flower.h"
#include "Shrub.h"

class PlantInfo;

class Builder
{

public:
	Builder();

	virtual void addCrop(string name) = 0;
	virtual void addPlant(PlantInfo p) = 0;
	Plant *getCrop();
	virtual void reset() = 0;
};

#endif
