#ifndef GARDENING_H
#define GARDENING_H
#include "Roles.h"

class Gardening : public Roles
{

public:
	Gardening();
	~Gardening();
	std::string getType() override;
	std::string jobDesc() override;
	std::vector<Plant *> plants;
	void update();
	void handleCustomer(Request* req) override;
	void handlePlant(Plant* p) override;
	void checkPlants();
};

#endif
