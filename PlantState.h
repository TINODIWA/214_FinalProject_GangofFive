#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include "PlantState.h"
#include <string>

using namespace std;

class PlantState {


public:
	PlantState();

	PlantState(const PlantState& other);
	virtual ~PlantState();

	virtual void handleChange() = 0;
	virtual string getState() = 0;
};

#endif
