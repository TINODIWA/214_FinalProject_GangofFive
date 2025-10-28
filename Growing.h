#ifndef GROWING_H
#define GROWING_H

class Growing : PlantState {
   public:
    Growing();

    Growing(const PlantState& other);

    void handleChange();
};

#endif
