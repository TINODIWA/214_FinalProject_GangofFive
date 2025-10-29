/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANTINFO_H_
#define PLANTINFO_H_

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "PlantCare.h"
#include "PlantState.h"

using namespace std;

class Staff;

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
    std::vector<int> days;
    int price;

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
    void setAmount(int amount);
    void setPrice(int price);
    void setDays(int days, int idx);

    std::string getName() const;
    std::string getType() const;
    std::vector<int> getWater() const;
    std::vector<int> getSun() const;
    std::vector<int> getFertiliser() const;
    std::vector<int> getDays() const;
    int getAttention() const;
    int getAmount() const;
    int getPrice()const;
    

  std::string getName() const;
  std::string getType() const;
  std::vector<int> getWater() const;
  std::vector<int> getSun() const;
  std::vector<int> getFertiliser() const;
  int getAttention() const;
  int getAmount() const;
  int getPrice() const;
};
#endif  // PLANTINFO_H_
