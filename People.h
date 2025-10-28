#ifndef PEOPLE_H
#define PEOPLE_H

#include "Nursery.h"
#include <string>

using namespace std;
class People
{

private:
	Nursery *nursery;

protected:
	string name;

public:
	People(Nursery *n);
	People();
	People(const People* other);

	void send(string m, Nursery *s, string type);
	void receive(string m, People *from, Nursery *n);
	string getName();
};

#endif
