#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

class PlantCreator {

private:
	Plant* plant;

protected:
	virtual Plant* produce() = 0;

public:
	void create();
};

#endif
