#ifndef PLANTCARE_H
#define PLANTCARE_H

class PlantCare {

private:
	WaterStrategy* water;
	SunStrategy* sun;
	FertiliseStrategy* fertilise;

public:
	int waterAlgorithm();

	int sunAlgorithm();

	int fertiliseAlgorithm();

	PlantCare();
};

#endif
