#ifndef PLANTCARE_H
#define PLANTCARE_H

#include "WaterStrategy.h"
#include "SunStrategy.h"
#include "FertiliseStrategy.h"

class PlantCare {

private:
	WaterStrategy* water;
	SunStrategy* sun;
	FertiliseStrategy* fertilise;

public:
	PlantCare(const PlantCare& other);

	int waterAlgorithm();

	int sunAlgorithm();

	int fertiliseAlgorithm();

	PlantCare();

	int changeAmount(int current, int required, int change);
};

#endif
