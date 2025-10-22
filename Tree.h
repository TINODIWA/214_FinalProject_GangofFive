#ifndef TREE_H
#define TREE_H

#include "Plant.h"

class Tree : public Plant
{

public:
	Tree(PlantInfo info);
	Tree();
	Tree(const Plant &other);

	~Tree();

	Plant *clone();
};

#endif
