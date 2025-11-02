#ifndef PLANTCARE_H_
#define PLANTCARE_H_

class PlantCare {
 private:
  bool checkPlant(int currWL, int WL, int changeDirection);
  virtual int changeAmount(int curr, int target) = 0;

 public:
  PlantCare(const PlantCare& other);
  PlantCare();
  virtual PlantCare* clone() = 0;
  virtual ~PlantCare();
  int apply(int currWL, int WL, int changeDirection = 1, int* currNL = nullptr, int NL = 0);
};


#endif
