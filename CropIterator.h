/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CROPITERATOR_H_
#define CROPITERATOR_H_

#include "Iterator.h"

class CropIterator : public Iterator {
 public:
  void first();
  void next();
  bool done();
  Garden* current();

  CropIterator* operator++();
  CropIterator* operator+();
};

#endif  // CROPITERATOR_H_
