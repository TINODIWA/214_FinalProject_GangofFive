#ifndef CARETAKER_H
#define CARETAKER_H

class CareTaker {

private:
	vector<Memento*> history;

public:
	void addMemento(Memento* m);

	Memento* getLastMemento();

	CareTaker();
};

#endif
