/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANT_H_
#define PLANT_H_

#include <map>
#include <string>
#include <vector>

#include "PlantCare.h"
#include "PlantState.h"
#include "Planted.h"

class Staff;

using namespace std;

class Plant {
 private:
  string name;
  string type;
  vector<int> water;
  vector<int> sun;
  vector<int> fertiliser;
  PlantCare* waterStrategy;
  PlantCare* sunStrategy;
  PlantCare* fertiliserStrategy;
  PlantState* state;
  vector<Staff*> staff;
  vector<int> days;  // <growing,mature>
  int price;

 public:
  Plant();
  virtual ~Plant();
  Plant(const Plant* other);
  Plant(string name, string type, vector<int> water, vector<int> sun, vector<int> fertiliser, 
        PlantCare* waterStrategy,PlantCare* sunStrategy, PlantCare* fertiliserStrategy, vector<int> days, int price);
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
  
  //vector[0] = current   vector[1] = required
  vector<int> getWater() const;
  vector<int> getSun() const;
  vector<int> getFertiliser() const;
  
  int getAttention() const;

  virtual Plant* clone() = 0;
  virtual void print() = 0;
  virtual void addPlant(Plant* p) = 0;

  // Observer functions
  void attach(Staff* s);
  void detach(Staff* s);
  void notify();
};

#endif  // PLANT_H_
