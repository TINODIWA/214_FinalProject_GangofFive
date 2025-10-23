#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

class Flower : public Plant {


public:
	Flower();
	Flower(const PlantInfo&  info);
	Flower(const Plant& other);
	~Flower();
	Plant* clone();
};

#endif
