/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef GARDENING_H_
#define GARDENING_H_

#include <vector>
#include <string>

class Gardening : public Roles {
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
