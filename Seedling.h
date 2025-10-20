#ifndef SEEDLING_H
#define SEEDLING_H

#include "Plant.h"

class Seedling : public Plant {

public:
	Seedling();

	Seedling(const Plant& other);

	~Seedling();

	Plant* clone();
};

#endif
