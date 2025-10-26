#include "Tree.h"

/**
 * @brief Construct a new Tree:: Tree object
 * 
 */
Tree::Tree():Plant() {}

/**
 * @brief Construct a new Tree:: Tree object
 * 
 * @param other 
 */
Tree::Tree(const Plant &other):Plant(other){}

/**
 * @brief Construct a new Tree:: Tree object
 * 
 * @param info 
 */
Tree::Tree(const PlantInfo&  info):Plant(info){}

/**
 * @brief Destroy the Tree:: Tree object
 * 
 */
Tree::~Tree() {}



/**
 * @brief stubbed 
 * 
 * @param p 
 */
void Tree::addPlant(const PlantInfo& p){}

/**
 * @brief Returns a clone of current plant 
 * @return Plant pointer
 */
Plant *Tree::clone()
{
	// TODO - implement Tree::clone
	throw "Not yet implemented";
}
