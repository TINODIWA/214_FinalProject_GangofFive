#ifndef DYING_H
#define DYING_H

class Dying : PlantState {


public:
	Dying();

	Dying(const PlantState& other);

	void handleChange();
};

#endif
