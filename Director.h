#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <iostream>
#include <sstream>
#include <map>
#include "Builder.h"
#include "CropBuilder.h"
#include "Crop.h"
#include "PlantInfo.h"

class Director
{

private:
	CropBuilder *cropBuilder;
	std::vector<PlantInfo> plants; 

public:
	Director();
	~Director();
	Director(Builder *p);
	void setBuilder(Builder *p);
	Plant *construct();
	void userInput();
};

#endif
