/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef GARDEN_H_
#define GARDEN_H_

class Garden {
 public:
  Garden();
  virtual ~Garden();
  virtual Garden* clone() = 0;
  virtual void add(Garden* p) = 0;
  virtual void print() = 0;
};

#endif  // GARDEN_H_
