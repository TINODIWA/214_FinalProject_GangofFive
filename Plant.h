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
#include <algorithm>  
#include <sstream>

#include "Garden.h"
#include "PlantCare.h"
#include "High.h"
#include "Medium.h"
#include "Low.h"
#include "PlantState.h"
#include "Planted.h"

class Staff;

using namespace std;

class Plant : public Garden {
 private:
  string name;
  string type;
  int sun;
  vector<int> water;
  vector<int> fertiliser;
  PlantCare* waterStrategy;
  PlantCare* sunStrategy;
  PlantCare* fertiliserStrategy;
  PlantState* state;
  vector<Staff*> staff;
  vector<int> days;  // <growing,mature>
  float price;
  int attention;
  PlantCare* setCareStrategy(char level);

 public:
  Plant();
  ~Plant();
  Plant(const Plant& other);
  void setName(string name);
  void setType(string type);
  void setWater(int water);
  void setSun(int sun);
  void setFertiliser(int fertiliser);
  void setAttention(int attention);
  void setWaterCare(char level);
  void setSunCare(char level);
  void setFertiliserCare(char level);
  void setDays(vector<int> days);
  void setPrice(float price);

  string getName() const;
  string getType() const;
  int getAttention() const;
  PlantCare* getWaterCare() const;
  PlantCare* getSunCare() const;
  PlantCare* getFertiliserCare() const;
  vector<int> getDays() const;
  float getPrice() const;
  // vector[0] = current   vector[1] = required
  vector<int> getWater() const;
  int getSun() const;
  vector<int> getFertiliser() const;

  Garden* clone();
  string print();
  bool operator==(string name);

  // Observer functions
  void attach(Staff* s);
  void detach(Staff* s);
  void notify();
  string advice();

  void updateWaterLevel(int newLevel);
  void updateSunLevel(int newLevel);
  void transpire(int decreasedLevel);
  void updateFertiliserLevel(int newLevel);
  void updateDay();
  string getState();
};

#endif  // PLANT_H_
