
/**
 * @file PlantCare.cpp
 * @author Dominique Nigatu
 * @brief Implementation of the PlantCare class for the plant care template method
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "PlantCare.h"


/**
 * @brief Copy constructor for PlantCare
 * @param other The PlantCare object to copy from
 */
PlantCare::PlantCare(const PlantCare& other) {}


/**
 * @brief Construct a new PlantCare object
 */
PlantCare::PlantCare() {
  
}


/**
 * @brief Destroy the PlantCare object
 */
PlantCare::~PlantCare() {
  
}

/**
 * @brief Applies care to the plant based on current and target water levels and change direction.
 * @param currWL Current water level
 * @param WL Target water level
 * @param changeDirection Direction of change (1 for increase, -1 for decrease)
 * @return int Updated current water level after applying care
 */
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
      return currWL;      //already at or above target lil kid
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

/**
 * @brief Checks if the plant needs care based on current and target water levels and change direction.
 * @param currWL Current water level
 * @param WL Target water level
 * @param changeDirection Direction of change (1 for increase, -1 for decrease)
 * @return bool True if care is needed, false otherwise
 */
bool PlantCare::checkPlant(int currWL, int WL, int changeDirection) {
  if (changeDirection > 0) {  //where its inc
    return currWL < WL;     //only apply if current is less than target
  } else {    //where its dec
    return currWL > 0;     //only apply if current is greater than 0
  }
}


//the idea sorta, and an example 
// Watering increase
// lowCare->apply(3, 8, 1);     // +1 water level
// mediumCare->apply(3, 8, 1);  // +2 water level  
// highCare->apply(3, 8, 1);    // +3 water level

// Sun exposure decrease
// lowCare->apply(5, 8, -1);    // -1 water level 
// mediumCare->apply(5, 8, -1); // -2 water level
// highCare->apply(5, 8, -1);   // -3 water level

//hope this makes sense
