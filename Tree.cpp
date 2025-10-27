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
void Tree::addPlant(Plant *p){}

/**
 * @brief Create a copy of this Tree.
 * @return Pointer to a new Tree.
 */
Plant *Tree::clone() {
	return new Tree(*this);
}


/**
 * @brief prints the plant 
 * 
 */
void Tree::print(){
	cout<<"Plant Name: "<<info.getName()<<"\n";
}