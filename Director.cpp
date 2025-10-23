#include "Director.h"

/**
 * @brief Construct a new Director:: Director object
 *
 */
Director::Director() : cropBuilder(nullptr) {}


/**
 * @brief Destroy the Director:: Director object
 * 
 */
Director::~Director()
{
	if (cropBuilder)
	{
		delete cropBuilder;
		cropBuilder = nullptr;
	}
}

/**
 * @brief Construct a new Director:: Director object
 *
 * @param p plant builder
 */
Director::Director(Builder *p) : cropBuilder(new CropBuilder(p)) {}

/**
 * @brief sets the plant builder to a new one
 *
 * @param p
 */
void Director::setBuilder(Builder *p)
{
	if (cropBuilder)
	{
		delete cropBuilder;
		cropBuilder = nullptr;
	}

	cropBuilder = new CropBuilder();
}

/**
 * @brief build the garden of crops
 *
 */
Plant *Director::construct()
{
	cropBuilder->reset();

	for (auto plant : plants)
	{
		cropBuilder->addCrop(plant.getType());
		cropBuilder->addPlant(plant);
	}
}

/**
 * @brief gets user input for the garden
 *
 */

void Director::userInput()
{
	/***
	 * THIS WILL BE A FOR LOOP THAT WILL POPULATE THE VECTOR OF STRUCTS WITH THE DIFFERENT PLANTS THE USER WANTS
	 */
}