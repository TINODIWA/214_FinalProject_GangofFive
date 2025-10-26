#ifndef TREE_H
#define TREE_H

#include "Plant.h"

/**
 * @class Tree
 * @brief ConcretePrototype of Plant subclass representing a tree.
 *
 * ConcretePrototype, subclass of Plant that implements cloning.
 */
class Tree : public Plant {
public:
    /** @brief Default constructor. */
    Tree();

    /** @brief Construct from an existing Plant. */
    Tree(const Plant& other);

    /** @brief Virtual destructor. */
    virtual ~Tree();

    /**
     * @brief Create a copy of this Tree.
     * @return Pointer to a new Tree.
     */
    virtual Plant* clone() override;
};

#endif
