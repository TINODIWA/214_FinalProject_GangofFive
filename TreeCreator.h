#ifndef TREECREATOR_H
#define TREECREATOR_H

#include "PlantCreator.h"
#include "Tree.h"

class PlantInfo;

class TreeCreator : public PlantCreator {
   public:
    TreeCreator();
    ~TreeCreator();
    TreeCreator(const PlantCreator *other);
    Plant *produce(const PlantInfo &info);
    PlantCreator *clone();
};

#endif
