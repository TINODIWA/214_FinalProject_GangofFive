/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef GROWING_H_
#define GROWING_H_
#include "PlantState.h"

class Growing : public PlantState {

public:
	Growing();

	Growing(const PlantState& other);

	void handleChange();
	string getState();
};

#endif  // GROWING_H_
