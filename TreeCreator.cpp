/**
 * @file TreeCreator.cpp
 * @author Unathi Tshakalisa
 * @brief File contains implementation of TreeCreator class. Returns an instance of Tree.
 */

#include "TreeCreator.h"

/**
 * @brief Tree Constrctor
 */
TreeCreator::TreeCreator() : PlantCreator() {}

/**
 * @brief Tree Destrctor
 */
TreeCreator::~TreeCreator() {}

/**
 * @brief Crates and returns an instance of Tree object
 * @param plantInfo Reference to PlantInfo for plant creation
 * @return instance of Tree 
 */
Plant *TreeCreator::produce(const PlantInfo &info)
{
	// TODO - implement TreeCreator::produce
	return new Tree(info);
}
