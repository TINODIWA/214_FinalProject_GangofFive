#include "CropBuilder.h"

/**
 * @brief Construct a new Crop Builder:: Crop Builder object
 *
 */
CropBuilder::CropBuilder() : Builder()
{}

/**
 * @brief ads a crop to the garden
 *
 * @param name
 */
void CropBuilder::addCrop(string name)
{
	Crop *crop = new Crop(name);
	root->addPlant(crop);
	currCrop = crop;
}

/**
 * @brief adds plants to the crop
 * 
 * @param p 
 */
void CropBuilder::addPlant(const PlantInfo& p)
{
	try
	{
		Plant *plant = factories.at(p.getType())->create(p);
		for (int i = 0; i < p.getAmount()-1; i++)
		{
			currCrop->addPlant(plant->clone());
		}
		currCrop->addPlant(plant);
	}
	catch (std::out_of_range err)
	{
		return;
	}
}


/**
 * @brief assigns the passed in list of factories to the crops builders list of factories
 * 
 * @param factories 
 */
void CropBuilder::setFactories(map<string, PlantCreator *> factories) {
	for(auto f: this->factories){
		factories[f.first] = f.second;
	}
}

/**
 * @brief adds the passed in factory to the crop builders list of factories
 * 
 * @param type 
 * @param factory 
 */
void CropBuilder::addFactory(std::string type,PlantCreator *factory) {
	if(factory)
		factories[type] = factory;
}

/**
 * @brief initialises a new garden
 *
 */
void CropBuilder::reset()
{
	root = new Crop("Garden");
	currCrop = root;
}