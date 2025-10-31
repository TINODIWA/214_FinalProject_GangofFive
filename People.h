/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PEOPLE_H_
#define PEOPLE_H_
#include "Nursery.h"
#include <string>

using namespace std;
class People {
 private:
  vector<Nursery*> communication;

 public:
  People(Nursery* n);
  People();
  People(const People* other);

  void send(string m, People* to, Nursery* n, string type);
  void send(string m, Nursery* n);
  void receive(string m, People* from, Nursery* n);
};

#endif  // PEOPLE_H_
