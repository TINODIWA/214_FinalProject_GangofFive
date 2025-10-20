#ifndef DEAD_H
#define DEAD_H

class Dead : PlantState {


public:
	Dead();

	Dead(const PlantState& other);

	void handleChange();
};

#endif
