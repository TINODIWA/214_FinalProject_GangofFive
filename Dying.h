/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef DYING_H_
#define DYING_H_
#include "PlantState.h"
class Dying : PlantState {
 public:
  Dying();

  Dying(const PlantState& other);

<<<<<<< HEAD
public:
	Dying();

	Dying(const PlantState& other);

	
	void handleChange();
=======
  void handleChange();
>>>>>>> 282cbf42c9195afab4bfb956e3d97ccbde640617
};

#endif  // DYING_H_
