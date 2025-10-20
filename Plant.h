#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <vector>
#include <map>

#include "PlantState.h"
#include "PlantCare.h"
#include "Staff.h"

using namespace std;

class Plant {	

protected:
	string type;
	string name;
	map<string, vector<int>> requirements;
	PlantState* state;
	PlantCare* strategy;
	Staff* staff;

public:
	Plant();

	~Plant();	

	Plant(const Plant& other);

	void setName(string name);

	void setType(string type);

	void setWaterLevel(int water);

	void setSun(int sun);

	void setFertiliser(int fertiliser);

	void setAttention(int attention);

	string getName() const;

	string getType() const;

	int getWaterLevel() const;

	int getSun() const;

	int getFertiliser() const;

	int getAttention() const;

	virtual Plant* clone() = 0;

	void attach(Staff* s);

	void detach(Staff* s);

	void notify();
};

#endif
