/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef GROWING_H_
#define GROWING_H_

class Growing : PlantState {
 public:
  Growing();

  explicit Growing(const PlantState& other);

  void handleChange();
};

#endif  // GROWING_H_
