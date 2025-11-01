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

  PlantCare();
};

class High : public PlantCare{

};

class Med : public PlantCare{

};

class Low : public PlantCare{

};

#endif  // PLANTCARE_H_
