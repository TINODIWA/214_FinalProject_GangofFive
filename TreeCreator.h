/**
 * @copyright Copyright (c) 2025
 */

#ifndef TREECREATOR_H_
#define TREECREATOR_H_

#include "PlantCreator.h"
#include "Tree.h"

class PlantInfo;

class TreeCreator : public PlantCreator {
 public:
  TreeCreator();
  ~TreeCreator();
  TreeCreator(const PlantCreator* other);
  Plant* produce(const PlantInfo& info);
  PlantCreator* clone();
};

#endif  // TREECREATOR_H_
