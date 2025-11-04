/**
 * @file CropBuilder.cpp
 * @author Swelihle Makhathini
 * @brief Implementation of the CropBuilder class, which constructs hierarchical garden structures
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "CropBuilder.h"

/**
 * @brief Construct a new Crop Builder:: Crop Builder object
 *
 */
CropBuilder::CropBuilder() : Builder(), root(nullptr), currCrop(nullptr) {}

/**
 * @brief Destructs CropBuilder object
 *
 */
CropBuilder::~CropBuilder() {
  if (root) {
    delete root;
    root = nullptr;
    currCrop = nullptr;
  }
}
/**
 * @brief Copy constructor for CropBuilder
 * @param other The CropBuilder to copy from
 */
CropBuilder::CropBuilder(const CropBuilder* other) {
  if (!other) {
    this->root = nullptr;
    return;
  }

  this->root = other->root ? other->root->clone() : nullptr;
  this->currCrop = this->root;
}

/**
 * @brief Add a new crop to the garden
 */
void CropBuilder::add() {
  Crop* crop = new Crop();
  root->add(crop);
  currCrop = crop;
}

/**
 * @brief Add a plant to the current crop
 * @param p The plant to add to the crop
 */
void CropBuilder::add(Garden* p) {
  currCrop->add(p);
}

/**
 * @brief Reset the builder state and create a new empty garden
 */
void CropBuilder::reset() {
  root = new Crop();
  currCrop = root;
}

/**
 * @brief Get the built crop
 * @return Pointer to the constructed garden
 */
Garden* CropBuilder::getCrop() {
  return this->root;
}

/**
 * @brief Create a copy of this builder
 * @return Pointer to the new CropBuilder instance
 */
CropBuilder* CropBuilder::clone(){
  return new CropBuilder(this);
 }
