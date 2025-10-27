#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

#include <iostream>
#include "Plant.h"

class PlantCreator {

protected:
	virtual Plant* produce(const PlantInfo& info) = 0;

public:
	virtual ~PlantCreator();
	Plant* create(const PlantInfo& plantInfo);
};

#endif
