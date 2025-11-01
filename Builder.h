#ifndef BUILDER_H
#define BUILDER_H

class Builder {


public:
	Builder();

	virtual void addCrop(Crop* c) = 0;

	virtual void addTree(Tree* t) = 0;

	virtual void addFlower(Flower f) = 0;

	virtual void addShrub(Shrub s) = 0;

	void reset();
};

#endif
