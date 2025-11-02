#ifndef PLANTED_H
#define PLANTED_H

class Planted : PlantState {


public:
	Planted();

	Planted(const PlantState& other);

	void handleChange();
};

#endif
