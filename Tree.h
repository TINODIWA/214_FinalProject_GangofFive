#ifndef TREE_H
#define TREE_H

#include <iomanip>
#include "Plant.h"

class Tree : public Plant
{
	public:
		Tree();
		Tree(const PlantInfo &info);
		Tree(const Plant &other);
		virtual ~Tree();
		void addPlant(Plant *p);
		Plant *clone();
		
		void print();
};

#endif
