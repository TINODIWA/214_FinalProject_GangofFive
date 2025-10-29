/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef DEAD_H_
#define DEAD_H_
#include "PlantState.h"
class Dead : PlantState {
   public:
    Dead();

    Dead(const PlantState& other);

    void handleChange();
};

#endif  // DEAD_H_
