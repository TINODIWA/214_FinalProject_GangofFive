/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANT_H_
#define PLANT_H_

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "Garden.h"
#include "PlantCare.h"
#include "PlantState.h"
#include "Planted.h"

class Staff;

using namespace std;

class Plant : public Garden {
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
  int attention;

 public:
  Plant();
  virtual ~Plant();
  Plant(const Plant& other);
  void setName(string name);
  void setType(string type);
  void setWater(int water);
  void setSun(int sun);
  void setFertiliser(int fertiliser);
  void setAttention(int attention);
  void setWaterCare(PlantCare* water);
  void setSunCare(PlantCare* sun);
  void setFertiliserCare(PlantCare* fertiliser);
  void setDays(vector<int> days);
  void setPrice(int price);

  string getName() const;
  string getType() const;
  int getAttention() const;
  PlantCare* getWaterCare() const;
  PlantCare* getSunCare() const;
  PlantCare* getFertiliserCare() const;
  vector<int> getDays() const;
  int getPrice() const;
  // vector[0] = current   vector[1] = required
  vector<int> getWater() const;
  vector<int> getSun() const;
  vector<int> getFertiliser() const;

  Garden* clone();
  void print();
  void add(Garden* p);

  // Observer functions
  void attach(Staff* s);
  void detach(Staff* s);
  void notify();
  string advice();
};

#endif  // PLANT_H_
