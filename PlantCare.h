/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef PLANTCARE_H_
#define PLANTCARE_H_


class PlantCare {
 private:

 public:
  PlantCare(const PlantCare& other);
  virtual int apply(int current, int required, int change);
  virtual int changeAmount(int current, int required, int change);
  PlantCare();
};

class High : public PlantCare{

};

class Med : public PlantCare{

};

class Low : public PlantCare{

};

#endif  // PLANTCARE_H_
