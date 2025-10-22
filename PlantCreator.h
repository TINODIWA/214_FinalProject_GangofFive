#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

#include <iostream>
#include "Plant.h"

class PlantCreator {

private:
	Plant* plant;

protected:
	virtual Plant* produce() = 0;

public:

/**
 * @brief 
 * 
 * @param plantInfo  - string holding the plants attributes in the form 
 * 						requirement:<water,sun,fertilise>*strategy:PlantCareObject[water-waterImpl,sun-sunImpl,fertilise-impl]#staff:StaffObject\n;
 * @return Plant* 
 */
	Plant* create(PlantInfo* plantInfo);
};

#endif
