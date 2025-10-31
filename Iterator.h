/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "Garden.h"

class Iterator {
 public:
  Iterator();
  virtual ~Iterator();
  Iterator(const Iterator& other);
  virtual void first() = 0;
  virtual void next() = 0;
  virtual bool done() = 0;
  virtual Garden* current() = 0;
};

#endif  // ITERATOR_H_
