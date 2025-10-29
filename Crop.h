/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CROP_H_
#define CROP_H_

#include <iostream>
#include <string>
#include <vector>

#include "Plant.h"

using namespace std;

class Crop : public Plant {
   public:
    std::vector<Plant *> plants;

    Crop();
    ~Crop();
    Crop(const Crop &other);
    Crop(std::string name);
    void addPlant(Plant *p);
    Plant *clone();
    void print();
};

#endif  // CROP_H_
