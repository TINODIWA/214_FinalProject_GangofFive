#ifndef ORDER_H
#define ORDER_H

class Order {

private:
	vector<Plants*> plants;
	Customer* customer;

public:
	Order();

private:
	void prepare();

	void payment();

	void package();

public:

	void addPlant(Plant* p);

	void removePlant(Plant* p);

	void purchase();
};

#endif
