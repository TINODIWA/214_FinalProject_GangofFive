#include "CropBuilder.h"

/**
 * @brief Construct a new Crop Builder:: Crop Builder object
 *
 */
CropBuilder::CropBuilder() : Builder(), p(nullptr), root(nullptr),currCrop(nullptr)
{}

/**
 * @brief 
 * 
 */
CropBuilder::~CropBuilder(){
	if(p){
		delete p;
		p = nullptr;
	}

	if(root){
		delete root;
		root = nullptr;
		currCrop = nullptr;
	}

	map<string, PlantCreator*>::iterator it = factories.begin();

	while(it != factories.end()){
		if((*it).second){
			delete (*it).second;
			(*it).second = nullptr;
		}

		++it;
	}
}
/**
 * @brief Construct a new Crop Builder:: Crop Builder object
 *
 * @param other
 */
CropBuilder::CropBuilder(const CropBuilder *other)
{
	 if (!other) {
		 this->root = nullptr;
		 this->p = nullptr;
		 return;
	 }

	 this->root = other->root ? other->root->clone() : nullptr;
	 this->p = other->p ? other->p->clone() : nullptr;

	 map<string, PlantCreator*>::const_iterator it = other->factories.begin();

	while(it != other->factories.end()){
		factories[(*it).first] = (*it).second;
		++it;
	}
	 
}
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
void CropBuilder::addPlant(const PlantInfo &p)
{
	cout<<"CropBuilder addPlant()\n";
	try
	{
		Plant *plant = factories.at(p.getType())->create(p);
		for (int i = 0; i < p.getAmount() - 1; i++)
		{
			cout<<"Adding a plant...\n";
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
void CropBuilder::setFactories(map<string, PlantCreator *> factories)
{
	for (auto f : this->factories)
	{
		factories[f.first] = f.second;
	}
}

/**
 * @brief adds the passed in factory to the crop builders list of factories
 *
 * @param type
 * @param factory
 */
void CropBuilder::addFactory(std::string type, PlantCreator *factory)
{
	if (factory)
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

/**
 * @brief Get the Crop object
 *
 * @return Plant*
 */
Plant *CropBuilder::getCrop()
{
	return this->root;
}