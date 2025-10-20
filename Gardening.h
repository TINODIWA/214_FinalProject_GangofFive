#ifndef GARDENING_H
#define GARDENING_H

class Gardening : Roles {

public:
	vector<Plant*> plants;

	Gardening();

	void update();

	string handleCustomer(Request* req);

	void handlePlant(Plant* p);

	string getType();

	void checkPlants();
};

#endif
