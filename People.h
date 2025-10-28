#ifndef PEOPLE_H
#define PEOPLE_H
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

#endif
