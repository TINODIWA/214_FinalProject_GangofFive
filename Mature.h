/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef MATURE_H_
#define MATURE_H_

class Mature : PlantState {
 public:
  Mature();

  explicit Mature(const PlantState& other);

  void handleChange();
};

#endif  // MATURE_H_
