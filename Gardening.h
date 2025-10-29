/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef GARDENING_H_
#define GARDENING_H_

#include <string>

class Gardening : Roles {
 public:
  vector<Plant*> plants;

  Gardening();

  void update();

  string handleCustomer(Request* req);

  void handlePlant(Plant* p);

  string getType();

  void checkPlants();
};

#endif  // GARDENING_H_
