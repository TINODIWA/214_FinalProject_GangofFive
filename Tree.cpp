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
Tree::Tree(const Plant &other):Plant(info){}

/**
 * @brief Construct a new Tree:: Tree object
 * 
 * @param info 
 */
Tree::Tree(PlantInfo info) {}

/**
 * @brief Destroy the Tree:: Tree object
 * 
 */
Tree::~Tree() {}

Plant *Tree::clone()
{
	// TODO - implement Tree::clone
	throw "Not yet implemented";
}
