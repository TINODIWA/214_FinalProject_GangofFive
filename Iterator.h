/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_

class Garden;

class Iterator {
 public:
  Iterator();
  virtual ~Iterator();
  Iterator(const Iterator& other);
  virtual Garden* first() = 0;
  virtual Garden* next() = 0;
  virtual bool done() = 0;
  virtual Garden* current() = 0;
  Garden* operator*();
 virtual  Iterator* operator++() = 0;
};

#endif  // ITERATOR_H_
