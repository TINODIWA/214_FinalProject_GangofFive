#ifndef SHRUB_H
#define SHRUB_H

#include <iomanip>
#include "Plant.h"

class Shrub : public Plant
{
	public:
		Shrub();
		Shrub(const PlantInfo &info);
		Shrub(const Plant &other);
		virtual ~Shrub();
		void addPlant(Plant *p);
		Plant *clone();

		void print();
};

#endif
