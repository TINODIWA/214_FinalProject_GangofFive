/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CROPITERATOR_H_
#define CROPITERATOR_H_

#include <stack>
#include "Iterator.h"
#include "Crop.h"

using namespace std;

class CropIterator : public Iterator {
 public:
  CropIterator();
  ~CropIterator();
  CropIterator(const CropIterator& other);
  CropIterator* first();
  CropIterator* next();
  bool done();
  Crop* current();
  Crop* operator[](int index);
  CropIterator* operator++();
  CropIterator* operator+();
};

#endif  // CROPITERATOR_H_
