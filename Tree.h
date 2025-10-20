#ifndef TREE_H
#define TREE_H

class Tree : Plant {


public:
	Tree();

	Tree(const Plant& other);

	Plant* clone();
};

#endif
