#ifndef TREECREATOR_H
#define TREECREATOR_H

#include "PlantCreator.h"
#include "Tree.h"

class PlantInfo;

class TreeCreator : public PlantCreator
{

public:
TreeCreator();
	~TreeCreator();
	Plant *produce(const PlantInfo&  info);
};

#endif
