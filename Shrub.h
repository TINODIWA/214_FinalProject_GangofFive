#ifndef SHRUB_H
#define SHRUB_H

#include "Plant.h"

/**
 * @class Shrub
 * @brief ConcretePrototype Plant subclass representing a shrub.
 *
 * ConcretePrototype, subclass of Plant that implements cloning.
 */
class Shrub : public Plant {
public:
    /** @brief Default constructor. */
    Shrub();

    /** @brief Construct from an existing Plant. */
    Shrub(const Plant& other);

    /** @brief Virtual destructor. */
    virtual ~Shrub();

    /**
     * @brief Create a copy of this Shrub.
     * @return Pointer to a new Shrub.
     */
    virtual Plant* clone() override;
};


#endif
