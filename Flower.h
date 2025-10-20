#ifndef FLOWER_H
#define FLOWER_H

class Flower : Plant {


public:
	Flower();

	Flower(const Plant& other);

	Plant* clone();
};

#endif
