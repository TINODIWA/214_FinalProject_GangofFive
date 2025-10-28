#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <vector>
#include <map>

#include "PlantInfo.h"

class PlantCare;
class Staff;

using namespace std;

class Plant {	

protected:
	PlantInfo info;

public:
	Plant();
	virtual ~Plant();	
	Plant(const Plant& other);
	Plant(const PlantInfo& info);
	virtual void addPlant(Plant *p) = 0;

	void setName(string name);
	void setType(string type);
	void setWater(int water);
	void setSun(int sun);
	void setFertiliser(int fertiliser);
	void setAttention(int attention);
	void setPlantCare(PlantCare* strategy);
	void setStaff(Staff* staff);
	void setPrice(int price);

	string getName() const;
	string getType() const;
	vector<int> getWater() const;
	vector<int> getSun() const;
	vector<int> getFertiliser() const;
	int getAttention() const;
	int getPrice()const;

	virtual Plant* clone() = 0;
	void attach(Staff* s);
	void detach(Staff* s);
	void notify();

	virtual void print() = 0;
};

#endif
