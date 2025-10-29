#ifndef PLANTED_H
#define PLANTED_H
#include "PlantState.h"
class Planted : public PlantState {


public:
	Planted();

	Planted(const PlantState& other);

	void handleChange();
	string getState();
};

#endif
