#ifndef CROP_H
#define CROP_H

#include <iostream>
#include <vector>
#include "Plant.h"

using namespace std;

class Crop : public Plant
{
public:
	std::vector<Plant *> plants;
	
	Crop();
	~Crop();
	Crop(const Crop& other);
	Crop(std::string name);
	void addPlant(Plant *p);
	Plant *clone();
	void print();
};

#endif
