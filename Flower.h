#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

/**
 * @class Flower
 * @brief ConcretePrototype of Plant subclass representing a flower.
 *
 * ConcretePrototype, subclass of Plant that implements cloning.
 */
class Flower : public Plant {
public:
    /** @brief Default constructor. */
    Flower();

    /** @brief Construct from an existing Plant. */
    Flower(const Plant& other);

    /** @brief Virtual destructor. */
    virtual ~Flower();

    /**
     * @brief Create a copy of this Flower.
     * @return Pointer to a new Flower.
     */
    virtual Plant* clone() override;
};

#endif
