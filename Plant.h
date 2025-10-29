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
	void setWater(int water,int  idx);
	void setSun(int sun,int idx);
	void setFertiliser(int fertiliser, int idx);
	void setAttention(int attention);
	void setPlantCare(PlantCare* strategy);
	void setStaff(Staff* staff);
	void setDays(int days);

	string getName() const;
	string getType() const;
	vector<int> getWater() const;
	vector<int> getSun() const;
	vector<int> getFertiliser() const;
	vector<int> getDays() const;
	int getAttention() const;


	virtual Plant* clone() = 0;
	void attach(Staff* s);
	void detach(Staff* s);
	void notify();

	void updateDay();
	void getState();

	virtual void print() = 0;
};

#endif
