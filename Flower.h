/**
 * @copyright Copyright (c) 2025
 *
 */
#ifndef FLOWER_H_
#define FLOWER_H_

#include <iomanip>
#include "Plant.h"

class Flower : public Plant {
   public:
    Flower();
    Flower(const PlantInfo& info);
    Flower(const Plant& other);
    void addPlant(Plant* p);
    ~Flower();
    Plant* clone();

    void print();
};

#endif  // FLOWER_H_
