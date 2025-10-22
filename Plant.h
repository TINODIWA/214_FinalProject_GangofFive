#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <vector>
#include <map>

#include "PlantInfo.h"
class PlantCare;
class PlantStaff;

using namespace std;

class Plant {	

protected:
	PlantInfo info;

public:
	Plant();
	~Plant();	
	Plant(const Plant& other);
	Plant(PlantInfo info);
	virtual void addPlant(Plant *p);

	void setName(string name);
	void setType(string type);
	void setWater(int water);
	void setSun(int sun);
	void setFertiliser(int fertiliser);
	void setAttention(int attention);
	void setPlantCare(PlantCare* strategy);
	void setStaff(Staff* staff);

	string getName() const;
	string getType() const;
	int getWater() const;
	int getSun() const;
	int getFertiliser() const;
	int getAttention() const;

	virtual Plant* clone() = 0;
	void attach(Staff* s);
	void detach(Staff* s);
	void notify();
};

#endif
