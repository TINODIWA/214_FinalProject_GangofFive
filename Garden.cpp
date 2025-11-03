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
Garden::Garden(){}

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
Iterator* Garden::createIterator() {
  return nullptr;
}

/**
 * @brief summary of number of plants in a crop - stubbed
 *
 * @return string
 */
map<string, int> Garden::summary(map<string, int>& sum) {
  return {};
}

/**
 * @brief adds a plant to a crop - stubbed
 *
 * @param p
 */
void Garden::add(Garden* p) {}

/**
 * @brief simulates loss of water due to transpiration - stubbed
 *
 * @param decreasedLevel
 */
void Garden::transpire(int decreasedLevel) {}

/**
 * @brief stubbed to return state of plant
 *
 */
string Garden::getState() {
  return "";
}

/**
 * @brief advice on what the plant needs to grow - stubbed
 *
 */
string Garden::advice() {
  return "";
}

/**
 * @brief return the plant with the passed in id
 *
 * @param name
 * @param num
 * @return Garden*
 */
vector<Garden*> Garden::get(string name, int num) {
  // cout<<"DEFAULT!!!\n";
  return {};
}

/**
 * @brief check if plants have equal ids
 *
 * @return true
 * @return false
 */
bool Garden::operator==(string name) {
  return false;
}

/**
 * @brief returns the plant with the passed in name - stubbed
 *
 */

Garden* Garden::get(string name) {
  return nullptr;
}
