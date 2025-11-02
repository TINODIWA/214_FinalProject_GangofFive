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
  
}

PlantCare::~PlantCare() {
  
}


int PlantCare::apply(int currWL, int WL, int changeDirection, int* currNL, int NL) {
  if (!checkPlant(currWL, WL, changeDirection)) {   //returns currWL if no change is needed
    return currWL;
  }

  int amount = changeAmount(currWL, WL);   //gets how much to change
  if (amount <= 0) {
    return currWL;
  }

  int change = amount * changeDirection;  //direction. -1 dcr and 1 inc
  
  // Apply to water level
  int newWaterLevel = currWL;
  if (changeDirection > 0) {  //inc
    int remaining = WL - currWL;      // how much more is needed
    if (remaining <= 0) {
      newWaterLevel = currWL;      //already at or above target
    } else {
      if (change > remaining) {      //cap at target level
        change = remaining;
      }
      newWaterLevel = currWL + change;
    }
  } else {
    if (currWL + change < 0) {      //max at 0. cant go 
      change = -currWL;
    }
    newWaterLevel = currWL + change;
  }

  //affects nutrients when dec, sun exposure
  if (changeDirection < 0 && currNL != nullptr && *currNL > 0) {
    int NAmount = changeAmount(*currNL, NL);
    int NChange = NAmount * changeDirection;
    
    if (*currNL + NChange < 0) {
      *currNL = 0;  //NL shouldnt go below 0
    } else {
      *currNL += NChange;
    }
  }

  return newWaterLevel;
}

/**
 * @brief Checks if the plant needs care based on current and target water levels and change direction.
 * @return True if care is needed, false otherwise.
 */
bool PlantCare::checkPlant(int currWL, int WL, int changeDirection) {
  if (changeDirection > 0) {  //where its inc
    return currWL < WL;     //only apply if current is less than target
  } else {    //where its dec
    return currWL > 0;     //only apply if current is greater than 0
  }
}