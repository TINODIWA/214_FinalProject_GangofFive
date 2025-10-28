#ifndef DEAD_H
#define DEAD_H
#include "PlantState.h"
class Dead : PlantState {
   public:
    Dead();

    Dead(const PlantState& other);

    void handleChange();
};

#endif
