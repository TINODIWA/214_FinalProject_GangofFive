#ifndef MATURE_H
#define MATURE_H
#include "PlantState.h"

class Mature : public PlantState {


public:
	Mature();

	Mature(const PlantState& other);

	void handleChange();
	string getState();
};

#endif
