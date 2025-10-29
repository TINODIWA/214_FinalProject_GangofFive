#ifndef GROWING_H
#define GROWING_H
#include "PlantState.h"

class Growing : public PlantState {


public:
	Growing();

	Growing(const PlantState& other);

	void handleChange();
	string getState();
};

#endif
