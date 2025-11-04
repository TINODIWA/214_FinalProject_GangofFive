/**
 * @file Iterator.cpp
 * @author Swelihle Makhathini
 * @brief Implementation of the Iterator class which provides traversal functionality for Garden objects
 * @version 0.1
 * @date 2025-10-31
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Iterator.h"

/**
 * @brief Construct a new Iterator object
 * 
 */
Iterator::Iterator(){}

/**
 * @brief Destroy the Iterator object
 * 
 */
Iterator::~Iterator(){}

/**
 * @brief Construct a new Iterator object
 * 
 * @param other 
 */
Iterator::Iterator(const Iterator& other){}

/**
 * @brief return the current element
 * 
 * @return Garden* 
 */
Garden* Iterator::operator*(){
    return current();
}

