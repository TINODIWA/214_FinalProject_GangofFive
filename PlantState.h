/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANTSTATE_H_
#define PLANTSTATE_H_

#include "PlantState.h"

class PlantState {
   public:
    PlantState();

    PlantState(const PlantState& other);

    virtual void handleChange() = 0;
};

#endif  // PLANTSTATE_H_
