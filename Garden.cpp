/**
 * @file Garden.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-30
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Garden.h"
#include "Iterator.h"

/**
 * @brief Construct a new Garden:: Garden object
 * 
 */
Garden::Garden() {}

/**
 * @brief Destroy the Garden:: Garden object
 * 
 */
Garden::~Garden() {}

/**
 * @brief creates an iterator for cropIterator and null for plants
 * 
 * @return Iterator* 
 */
Iterator* Garden::createIterator(){
    return nullptr;
}

/**
 * @brief simulates plants losing water as a result of sun exposure - stubbed
 * 
 */
void transpire(int decreasedLevel){}

/**
 * @brief summary of number of plants in a crop - stubbed
 * 
 * @return string 
 */
string Garden::summary(){
    return "";
}
