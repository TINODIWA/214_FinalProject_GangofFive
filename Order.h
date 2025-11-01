#ifndef ORDER_H
#define ORDER_H

class Order {

private:
	vector<Plants*> plants;
	Customer* customer;
	Memento* store;

public:
	Order();

private:
	void prepare();

	void payment();

	void package();

public:
	Memento* createMemento();

	void setMemento(Memento* m);

	void addPlant(Plant* p);

	void removePlant(Plant* p);

	void purchase();
};

#endif
