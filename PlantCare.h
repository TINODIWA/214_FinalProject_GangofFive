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

  int waterAlgorithm();

  int sunAlgorithm();

  int fertiliseAlgorithm();

  PlantCare();
};

#endif  // PLANTCARE_H_
