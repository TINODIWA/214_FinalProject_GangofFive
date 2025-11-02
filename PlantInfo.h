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

class Staff;

class PlantInfo {
 private:
 

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
