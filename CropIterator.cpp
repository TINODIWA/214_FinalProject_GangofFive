/**
 * @file CropIterator.cpp
 * @author Swelihle Makhathini
 * @brief
 * @version 0.1
 * @date 2025-11-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "CropIterator.h"

/**
 * @brief Construct a new Crop Iterator:: Crop Iterator object
 *
 * @param p
 */
CropIterator::CropIterator(vector<Garden*>& p) : plants(p), curr(p.begin()) {}

/**
 * @brief Destroy the Crop Iterator:: Crop Iterator object
 *
 */
CropIterator::~CropIterator() {}

/**
 * @brief Construct a new Crop Iterator:: Crop Iterator object
 *
 * @param other
 */
CropIterator::CropIterator(const CropIterator& other) : Iterator(other), plants(other.plants) {}

/**
 * @brief returns the first element and resets the current index to the beginning
 *
 * @return Garden*
 */
Garden* CropIterator::first() {
  curr = plants.begin();
  return current();
}

/**
 * @brief returns the next object and updates current
 *
 * @return Garden*
 */
Garden* CropIterator::next() {
  if (done()) return nullptr;
  Garden* next = *curr;

  ++curr;

  return next;
}

/**
 * @brief has the end of the vector been reached
 *
 * @return true
 * @return false
 */
bool CropIterator::done() {
  return curr == plants.end();
}

/**
 * @brief returns the current element being pointed to
 *
 * @return Garden*
 */
Garden* CropIterator::current() {
  return *curr;
}

/**
 * @brief increments the iterator
 *
 * @return Iterator*
 */
Iterator* CropIterator::operator++() {
  ++curr;
  return this;
}

/**
 * @brief removes the current element being pointed
 *
 * @return Garden*
 */
Garden* CropIterator::remove() {
  if (!plants.empty() && curr != plants.end()) {
    Garden* rem = (*curr);
    curr = plants.erase(curr);

    return rem;
  }
  return nullptr;
}

/**
 * @brief return the number of elements in the crop
 * 
 */

 int CropIterator::size(){
  return static_cast<int>(plants.size());
 }
