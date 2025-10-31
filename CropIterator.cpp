/**
 * @file CropIterator.cpp
 * @author Swelihle Makhathini
 * @brief
 * @version 0.1
 * @date 2025-10-31
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "CropIterator.h"

/**
 * @brief Construct a new Crop Iterator:: Crop Iterator object
 * 
 */
CropIterator::CropIterator(){}

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
CropIterator::CropIterator(const CropIterator& other) {
}

/**
 * @brief returns a reference to an iterator pointing to the root of the composite tree
 * 
 * @return CropIterator* 
 */
CropIterator* CropIterator::first() {
}

/**
 * @brief 
 * 
 * @return CropIterator* 
 */
CropIterator* CropIterator::next() {
    if(done) return nullptr;


}


bool CropIterator::done() {}
Crop* CropIterator::current() {}
Crop* CropIterator::operator[](int index) {}
CropIterator* CropIterator::operator++() {}
CropIterator* CropIterator::operator+() {}
