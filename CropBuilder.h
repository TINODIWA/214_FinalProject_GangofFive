#ifndef CROPBUILDER_H
#define CROPBUILDER_H

class CropBuilder : Builder {

private:
	Plant* root;
	Plant* currCrop;
	map<string, PlantCreator*> factories;

public:
	CropBuilder();

	void addCrop(Crop* c);

	void addTree(Tree* t);

	void addFlower(Flower* f);

	void addShrub(Shrub* s);

	void reset();

	Plant* getCrop();
};

#endif
