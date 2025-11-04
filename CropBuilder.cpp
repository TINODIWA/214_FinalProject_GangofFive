/**
 * @file CropBuilder.cpp
 * @author your name (you@domain.com)
 * @brief
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
 * @brief
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
 * @brief Construct a new Crop Builder:: Crop Builder object
 *
 * @param other
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
 * @brief ads a crop to the garden
 *
 * @param name
 */
void CropBuilder::add() {
  Crop* crop = new Crop();
  root->add(crop);
  currCrop = crop;
}

/**
 * @brief adds plants to the crop
 *
 * @param p
 */
void CropBuilder::add(Garden* p) {
  currCrop->add(p);
}

/**
 * @brief initialises a new garden
 *
 */
void CropBuilder::reset() {
  root = new Crop();
  currCrop = root;
}

/**
 * @brief Get the Crop object
 *
 * @return Plant*
 */
Garden* CropBuilder::getCrop() {
  return this->root;
}

/**
 * @brief clones the builder
 * 
 */

 CropBuilder* CropBuilder::clone(){
  return new CropBuilder(*this);
 }
