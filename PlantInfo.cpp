/**
 * @file PlantInfo.cpp
 * @authors Unathi Tshakalisa,
 * @brief File contains implementation of PlantInfo class. Used to hold details related to plants
 */

#include "PlantInfo.h"

/**
 * @brief Constructor for PlantInfo
 */
PlantInfo::PlantInfo() {}

/**
 * @brief Destructor for PlantInfo
 */
PlantInfo::~PlantInfo()
{
    if (staff)
        delete staff;

    if (strategy)
        delete strategy;
}

/**
 * @brief Copy Constructor for PlantInfo
 * @param plantInfo  Constant reference to object being copied
 */
PlantInfo::PlantInfo(const PlantInfo &plantInfo)
{
    this->name = plantInfo.name;
    this->type = plantInfo.type;
    this->water = plantInfo.water;
    this->sun = plantInfo.sun;
    this->fertiliser = plantInfo.fertiliser;
    this->strategy = new PlantCare(*plantInfo.strategy);
    this->state = plantInfo.state; // pointing at same reference for now...need to change
    this->staff = new Staff(*plantInfo.staff);
    this->amount = plantInfo.amount;
    this->days = plantInfo.days;
}

/**
 * @brief Sets the name attribute
 * @param name
 */
void PlantInfo::setName(std::string name)
{
    this->name = name;
}

/**
 * @brief Sets the type attribute
 * @param type
 */
void PlantInfo::setType(std::string type)
{
    this->type = type;
}

/**
 * @brief Sets the water attribute
 * @param water Value to set
 * @param idx Index in vector being set
 */
void PlantInfo::setWater(int water, int idx)
{
    if (idx < 0 || idx > 1)
    {
        cout << "Invalid Index!" << endl;
        return;
    }
    this->water[idx] = water;
}

/**
 * @brief Sets the sun attribute
 * @param sun Value to set
 * @param idx Index in vector being set
 */
void PlantInfo::setSun(int sun, int idx)
{
    if (idx < 0 || idx > 1)
    {
        cout << "Invalid Index!" << endl;
        return;
    }
    this->sun[idx] = sun;
}

/**
 * @brief Sets the fertiliser attribute
 * @param fertiliser Value to set
 * @param idx Index in vector being set
 */
void PlantInfo::setFertiliser(int fertiliser, int idx)
{
    if (idx < 0 || idx > 1)
    {
        cout << "Invalid Index!" << endl;
        return;
    }
    this->fertiliser[idx] = fertiliser;
}

void PlantInfo::setAttention(int attention)
{
}

/**
 * @brief Sets the strategy attribute
 * @param strategy Reference to strategy to set
 */
void PlantInfo::setPlantCare(PlantCare *strategy)
{
    this->strategy = strategy; // deep copy?
}

/**
 * @brief Sets the staff attribute
 * @param strategy Reference to staff to appoint
 */
void PlantInfo::setStaff(Staff *staff)
{
    this->staff = staff; // deep copy?
}

/**
 * @brief Name getter
 * @return name
 */
std::string PlantInfo::getName() const
{
    return name;
}

/**
 * @brief Type getter
 * @return type
 */
std::string PlantInfo::getType() const
{
    return type;
}

/**
 * @brief Water getter
 * @return water vector
 */
std::vector<int> PlantInfo::getWater() const
{
    return water;
}

/**
 * @brief Sun getter
 * @return sun vector
 */
std::vector<int> PlantInfo::getSun() const
{
    return sun;
}

/**
 * @brief Fertiliser getter
 * @return fertiliser vector
 */
std::vector<int> PlantInfo::getFertiliser() const
{
    return fertiliser;
}

int PlantInfo::getAttention() const
{
    return 0;
}

/**
 * @brief Amount getter
 * @return amount
 */
int PlantInfo::getAmount() const
{
    return amount;
}