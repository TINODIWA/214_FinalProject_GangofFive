/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANT_H_
#define PLANT_H_

#include <map>
#include <string>
#include <vector>

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
    virtual void addPlant(Plant* p) = 0;

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
    vector<int> getWater() const;
    vector<int> getSun() const;
    vector<int> getFertiliser() const;
    int getAttention() const;

    virtual Plant* clone() = 0;
    void attach(Staff* s);
    void detach(Staff* s);
    void notify();

    virtual void print() = 0;
};

#endif  // PLANT_H_
