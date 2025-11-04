/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CROPITERATOR_H_
#define CROPITERATOR_H_

#include "Iterator.h"
#include "Garden.h"

class CropIterator : public Iterator {
 private:
  vector<Garden*>& plants;
  vector<Garden*>::iterator curr;

 public:
  CropIterator(vector<Garden*>& p);
  ~CropIterator();
  CropIterator(const CropIterator& other);

  Garden* first();
  Garden* next();
  bool done();
  Garden* current();
  Iterator* operator++();
  Garden* remove();
  int size();
};

#endif  // CROPITERATOR_H_
