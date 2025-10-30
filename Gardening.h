#ifndef GARDENING_H
#define GARDENING_H

#include "Plant.h"
#include "Roles.h"

class Gardening : public Roles {

public:
    vector<Plant*> plants;

	~Gardening();
	
    Gardening();

    void update(Plant* p);

    string handleCustomer(Request* req);

    void handlePlant(Plant* p);

    string getType();

    void checkPlants();
};

#endif
