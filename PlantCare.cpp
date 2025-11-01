
/**
 * @file PlantCare.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "PlantCare.h"

PlantCare::PlantCare(const PlantCare& other) {}

// int PlantCare::waterAlgorithm() {
//   // TODO(user) - implement PlantCare::waterAlgorithm
//   // throw "Not yet implemented";
// }

// int PlantCare::sunAlgorithm() {
//   // TODO(user) - implement PlantCare::sunAlgorithm
//   // throw "Not yet implemented";
// }

// int PlantCare::fertiliseAlgorithm() {
//   // TODO(user) - implement PlantCare::fertiliseAlgorithm
//   // throw "Not yet implemented";
// }

PlantCare::PlantCare() {
  // TODO(user) - implement PlantCare::PlantCare
  // throw "Not yet implemented";
}

/**
 * @brief Apply care to adjust resource levels
 * Delegates to changeAmount for actual calculation
 * @param current Current resource level
 * @param required Target resource level
 * @param change Maximum amount to change
 * @return New resource level after applying care
 */
int PlantCare::apply(int current, int required, int change) {
  return changeAmount(current, required, change);
}

/**
 * @brief Calculate amount to change resource level
 * Increases current by up to change amount but never exceeds required
 * @param current Current resource level
 * @param required Target resource level
 * @param change Maximum amount to change
 * @return New resource level, never exceeding required
 */
int PlantCare::changeAmount(int current, int required, int change) {
  if (current >= required) return current;
  if (change <= 0) return current;
  int newVal = current + change;
  if (newVal > required) newVal = required;
  return newVal;
}