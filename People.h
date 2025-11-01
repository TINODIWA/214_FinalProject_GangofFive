/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PEOPLE_H_
#define PEOPLE_H_

#include "Nursery.h"
#include <string>
#include <iostream>

using namespace std;
class Nursery;
class People {
 protected:
  Nursery* nursery;
  string name;

 public:
  People();
  People(Nursery* n, string name);
  People(const People* other);
  virtual ~People();

  virtual void send(string m, Nursery* group, string type);
  virtual void send(string m, People* to, Nursery* group, string type);
  virtual void receive(string m, People* from, Nursery* group, string type) = 0;
  
  virtual string getName() const;
  virtual Nursery* getNursery() const;
  
  void setName(const string& name);
  void setNursery(Nursery* n);
};

#endif  // PEOPLE_H_
