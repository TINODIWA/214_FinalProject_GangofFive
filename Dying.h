#ifndef DYING_H
#define DYING_H
#include "PlantState.h"
class Dying : PlantState {
   public:
    Dying();

    Dying(const PlantState& other);

    void handleChange();
};

#endif
