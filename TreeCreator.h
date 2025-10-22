#ifndef TREECREATOR_H
#define TREECREATOR_H

#include "PlantCreator.h"
#include "Tree.h"

class PlantInfo;

class TreeCreator : PlantCreator
{

public:
	Plant *produce(PlantInfo* info);
};

#endif
