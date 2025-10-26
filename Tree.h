#ifndef TREE_H
#define TREE_H

#include "Plant.h"

class Tree : public Plant
{

public:
	Tree(const PlantInfo&  info);
	Tree();
	Tree(const Plant &other);
	void addPlant(const PlantInfo& p);
	virtual ~Tree();
	Plant *clone();
};

#endif
