#ifndef PLANTINFO_H
#define PLANTINFO_H

#include <iostream>
#include <map>
#include <vector>

#include "PlantCare.h"
#include "PlantState.h"
#include "Staff.h"

class PlantInfo
{
private:
    std::string name;
    std::string type;
    std::vector<int> water;
    std::vector<int> sun;
    std::vector<int> fertiliser;
    PlantCare *strategy;
    PlantState *state;
    Staff *staff;
    int amount; // number of plants in the garden ????? should this be here
    int days;

    
public:
    PlantInfo();
    ~PlantInfo();
    PlantInfo(const PlantInfo& p);

    void setName(std::string name);
    void setType(std::string type);
    void setWater(int water, int idx);
    void setSun(int sun, int idx);
    void setFertiliser(int fertiliser, int idx);
    void setAttention(int attention);
    void setPlantCare(PlantCare* strategy);
	void setStaff(Staff* staff);

    std::string getName() const;
    std::string getType() const;
    std::vector<int> getWater() const;
    std::vector<int> getSun() const;
    std::vector<int> getFertiliser() const;
    int getAttention() const;
    int getAmount() const;

};
#endif