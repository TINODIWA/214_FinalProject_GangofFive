#ifndef MEMENTO_H
#define MEMENTO_H

class Memento {

private:
	vector<Plant*> plants;

public:
	Memento(vector<Plant*>& currP);

	Memento();

	vector<Plant*> getPlants();
};

#endif
