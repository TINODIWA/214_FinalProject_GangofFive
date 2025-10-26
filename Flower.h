#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

class Flower : public Plant {
	
public:
	Flower();
	Flower(const PlantInfo&  info);
	Flower(const Plant& other);
	void addPlant(const PlantInfo& p);
	virtual ~Flower();
	Plant* clone();

	void print();
};

#endif
