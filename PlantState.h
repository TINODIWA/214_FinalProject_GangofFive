#ifndef PLANTSTATE_H
#define PLANTSTATE_H

class PlantState {


public:
	PlantState();

	PlantState(const PlantState& other);

	virtual void handleChange() = 0;
};

#endif
