#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>

#include "Crop.h"
#include "Flower.h"
#include "Shrub.h"
#include "Tree.h"

class PlantInfo;

class Builder {
   public:
    Builder();
    virtual ~Builder();
    virtual void addCrop(string name) = 0;
    virtual void addPlant(const PlantInfo& p) = 0;
    virtual void reset() = 0;
};

#endif
