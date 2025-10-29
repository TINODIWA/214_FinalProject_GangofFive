/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef TREE_H_
#define TREE_H_

#include "Plant.h"
#include <iomanip>

class Tree : public Plant {
 public:
  Tree(const PlantInfo& info);
  Tree();
  Tree(const Plant& other);
  void addPlant(Plant* p);
  virtual ~Tree();
  Plant* clone();
  void print();
};

#endif  // TREE_H_
