#ifndef SHRUB_H
#define SHRUB_H

class Shrub : Plant {


public:
	Shrub();

	Shrub(const Plant& other);

	Plant* clone();
};

#endif
