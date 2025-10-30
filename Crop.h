#ifndef CROP_H
#define CROP_H

#include <iostream>
#include <vector>
#include "Plant.h"

using namespace std;

class Crop : public Plant
{
	public:
		Crop();
		~Crop();
		Crop(const Crop& other);
		Crop(string name);
		void addPlant(Plant *p);
		Plant *clone();
		void print();

	private:
		string name;
		vector< Plant *> plants;
};

#endif
