/**
 * @file PlantState.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "PlantState.h"
#include "Plant.h"

/**
 * @brief Construct a new Plant State:: Plant State object
 *
 */
PlantState::PlantState() {}

/**
 * @brief Construct a new Plant State:: Plant State object
 *
 * @param other
 */
PlantState::PlantState(const PlantState& other) {}

/**
 * @brief Destroy the Plant State:: Plant State object
 *
 */
PlantState::~PlantState() {}

/**
 * @brief checks if the plant has its required water and fertiliser
 * 
 * @param p 
 * @return true 
 * @return false 
 */
bool PlantState::dying(Plant* p) {
  bool bad = false;

  vector<int> water = p->getWater();
  vector<int> fertiliser = p->getFertiliser();

  if (water[0] != water[1]) bad = true;
  if (fertiliser[0] != fertiliser[1]) bad = true;

  return bad;
}

/**
 * @brief sets previous state for dying - stubbed
 * 
 * @param prev 
 */
void PlantState::setPrev(PlantState* prev){}
