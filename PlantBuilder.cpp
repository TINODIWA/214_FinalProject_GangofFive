#include "PlantBuilder.h"

/**
 * @brief Construct a new Plant Builder:: Plant Builder object
 *
 */
PlantBuilder::PlantBuilder() {}

/**
 * @brief Destroy the Plant Builder:: Plant Builder object
 *
 */

PlantBuilder::~PlantBuilder() {}

/**
 * @brief sets the name of the plant
 *
 * @param name
 * @return Builder*
 */
PlantBuilder *PlantBuilder::setName(string name)
{
    p->setName(name);
    return this;
}

/**
 * @brief sets the type of plant
 *
 * @param type
 * @return Builder*
 */
PlantBuilder *PlantBuilder::setType(string type)
{
    p->setType(type);
    return this;
}

PlantBuilder *PlantBuilder::setWater(int water) {}

PlantBuilder *PlantBuilder::setSun(int sun) {}

PlantBuilder *PlantBuilder::setFertiliser(int fertiliser) {}
/**
 * @brief sets the strategy for the plant
 *
 * @param strategy
 * @return Builder*
 */
PlantBuilder *PlantBuilder::setPlantCare(PlantCare *strategy)
{
   p->setPlantCare(strategy);
    return this;
}

/**
 * @brief sets the staff for the plant
 *
 * @param staff
 * @return Builder*
 */
PlantBuilder *PlantBuilder::setStaff(Staff *staff)
{
    p->setStaff(staff);
    return this;
}

/**
 * @brief instantiates the plant
 *
 * @return Plant*
 */
Plant *PlantBuilder::build()
{
    // if (type == "Flower")
    //     return new Flower(name, requirements);
    // if (type == "Tree")
    //     return new Tree(name, requirements);
    // if (type == "Shrub")
    //     return new Shrub(name, requirements);
}