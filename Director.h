/**
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef DIRECTOR_H_
#define DIRECTOR_H_

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
	Builder *cropBuilder;

public:
	Director();
	~Director();
	Director(Builder *p);
	void setBuilder(Builder *p);
	Plant *construct();
	void userInput();
};

#endif // DIRECTOR_H_
