#ifndef CROP_H
#define CROP_H

class Crop : Plant {

public:
	vector<Plant*> plants;

	Crop();

	void addCrop(Crop* c);

	void addPlant(Plant* p);

	Plant* clone();
};

#endif
