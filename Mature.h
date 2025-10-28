#ifndef MATURE_H
#define MATURE_H

class Mature : PlantState {
   public:
    Mature();

    Mature(const PlantState& other);

    void handleChange();
};

#endif
