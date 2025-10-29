/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PEOPLE_H_
#define PEOPLE_H_
#include <string>
#include "Nursery.h"

using namespace std;
class People {
   private:
    Nursery* nursery;

   public:
    People(Nursery* n);

    People();
    People(const People* other);

    void send(string m, Nursery* s, string type);

    void receive(string m, People* from, Nursery* n);
};

#endif  // PEOPLE_H_
