#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

#include <iostream>
#include "Plant.h"

class PlantCreator {

private:
	Plant* plant;

protected:
	virtual Plant* produce(PlantInfo* info) = 0;

public:

	Plant* create(PlantInfo* plantInfo);
};

#endif
