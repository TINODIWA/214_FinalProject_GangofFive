#ifndef PEOPLE_H
#define PEOPLE_H

class People {

private:
	Nursery* nursery;

public:
	People(Nursery* n);

	People();

	void send(string m, Nursery* s, string type);

	void receive(string m, People* from, Nursery* n);
};

#endif
