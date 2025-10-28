#ifndef FLOWER_H
#define FLOWER_H

#include <iomanip>
#include "Plant.h"

class Flower : public Plant 
{
	public:
		Flower();
		Flower(const PlantInfo &info);
		Flower(const Plant &other);
		virtual ~Flower();
		void addPlant(Plant *p);
		Plant *clone();

		void print();
};

#endif
