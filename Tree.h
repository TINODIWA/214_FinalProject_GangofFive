#ifndef TREE_H
#define TREE_H

#include "Plant.h"

class Tree : public Plant
{

public:
	Tree(const PlantInfo&  info);
	Tree();
	Tree(const Plant &other);
	void addPlant(Plant *p);
	virtual ~Tree();
	Plant *clone();
	void print();
};

#endif
