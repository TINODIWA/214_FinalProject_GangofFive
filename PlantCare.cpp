
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
  //TODO
}

PlantCare::~PlantCare() {
  //TODO
}

int PlantCare::apply(int currWL, int WL, int changeDirection) {
  if (!checkPlant(currWL, WL, changeDirection)) {   //returns currWL if no change is needed
    return currWL;
  }

  int amount = changeAmount(currWL, WL);   //gets how much to change
  if (amount <= 0) {
    return currWL;
  }

  int change = amount * changeDirection;  //direction. -1 dcr and 1 inc
  
  if (changeDirection > 0) {  //inc
    int remaining = WL - currWL;      // how much more is needed
    if (remaining <= 0) {
      return currWL;      //already at or above target
    }
    if (change > remaining) {      //cap at target level
      change = remaining;
    }
  } else {
    if (currWL + change < 0) {      //max at 0. cant go 
      change = -currWL;
    }
  }

  return currWL + change;
}


bool PlantCare::checkPlant(int currWL, int WL, int changeDirection) {
  if (changeDirection > 0) {  //where its inc
    return currWL < WL;     //only apply if current is less than target
  } else {    //where its dec
    return currWL > 0;     //only apply if current is greater than 0
  }
}
