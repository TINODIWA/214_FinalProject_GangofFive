/**
 * @file CropIterator.cpp
 * @author Swelihle Makhathini
 * @brief Implementation of the CropIterator class, which provides iteration functionality over a collection of Garden objects
 * @version 0.1
 * @date 2025-11-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "CropIterator.h"

/**
 * @brief Construct a new CropIterator object
 * @param p Reference to the vector of Garden pointers to iterate over
 */
CropIterator::CropIterator(vector<Garden*>& p) : plants(p), curr(p.begin()) {}

/**
 * @brief Destroy the Crop Iterator:: Crop Iterator object
 *
 */
CropIterator::~CropIterator() {}

/**
 * @brief Copy construct a new CropIterator object
 * @param other The iterator to copy from
 */
CropIterator::CropIterator(const CropIterator& other) : Iterator(other), plants(other.plants) {}

/**
 * @brief Get the first element and reset the iterator position
 * @return Pointer to the first Garden object, or nullptr if empty
 */
Garden* CropIterator::first() {
  curr = plants.begin();
  return current();
}

/**
 * @brief Get the next element and advance the iterator
 * @return Pointer to the next Garden object, or nullptr if at end
 */
Garden* CropIterator::next() {
  if (done()) return nullptr;
  Garden* next = *curr;

  ++curr;

  return next;
}

/**
 * @brief Check if iteration is complete
 * @return true if at end of collection, false otherwise
 */
bool CropIterator::done() {
  return curr == plants.end();
}

/**
 * @brief Get the current element without advancing
 * @return Pointer to the current Garden object
 */
Garden* CropIterator::current() {
  return *curr;
}

/**
 * @brief Advance the iterator to the next element
 * @return Pointer to this iterator
 */
Iterator* CropIterator::operator++() {
  ++curr;
  return this;
}

/**
 * @brief Remove and return the current element
 * @return Pointer to the removed Garden object, or nullptr if invalid
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
 * @brief Get the number of elements in the collection
 * @return The number of elements in the crop
 */
int CropIterator::size(){
  return static_cast<int>(plants.size());
 }
