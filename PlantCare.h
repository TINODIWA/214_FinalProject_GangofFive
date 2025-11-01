/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANTCARE_H_
#define PLANTCARE_H_

class PlantCare {
 private:
  bool checkPlant();
  virtual int changeAmount() = 0;

 public:
  PlantCare(const PlantCare& other);
  PlantCare();  // IS THIS NEEDED HERE
  virtual ~PlantCare();
  int apply(int currWL, int WL, int);
};

// class High : public PlantCare{

// };

// class Med : public PlantCare{

// };

// class Low : public PlantCare{

// };

#endif  // PLANTCARE_H_
