#ifndef CROPBUILDER_H
#define CROPBUILDER_H

#include <vector>
#include "PlantCare.h"
#include "Staff.h"
#include "Builder.h"
#include "PlantCreator.h"
#include "TreeCreator.h"
#include "FlowerCreator.h"
#include "ShrubCreator.h"
class PlantInfo;

class CropBuilder : public Builder
{

private:
	Plant* p;
	Plant *root;
	Plant *currCrop;
	map<string, PlantCreator *> factories;

public:
	CropBuilder();
	CropBuilder(map<string, PlantCreator *> factories, std::map<std::string, int> crops);
	void addCrop(string name);
	void addPlant(PlantInfo p);
	void setFactories(map<string, PlantCreator *> factories);
	void addFactory(std::string type,PlantCreator *factory);
	void reset();

	Plant* build();
};

#endif
