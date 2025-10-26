#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include "PlantState.h"

class PlantState {


public:
	PlantState();

	PlantState(const PlantState& other);

	virtual void handleChange() = 0;
};

#endif
