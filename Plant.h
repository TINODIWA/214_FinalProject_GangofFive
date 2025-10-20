#ifndef PLANT_H
#define PLANT_H

class Plant {

protected:
	String type;
	string name;
	string requirements;
	PlantState* state;
	PlantCare* strategy;
	Staff* staff;

public:
	Plant();

	Plant(const Plant& other);

	void setName(string name);

	void setType(string type);

	Plant(string name, string type, int water, int sun, int fertiliser, int attention);

	void setWater(int water);

	void setSun(int sun);

	void setFertiliser(int fertiliser);

	void setAttention(int attention);

	string getName();

	string getType();

	int getWater();

	int getSun();

	int getFertiliser();

	int getAttention();

	virtual Plant* clone() = 0;

	void attach(Staff* s);

	void detach(Staff* s);

	void notify();
};

#endif
