#ifndef DIRECTOR_H
#define DIRECTOR_H

class Director {

private:
	PlantBuilder* plantBuilder;

public:
	Director();

	Director(PlantBuilder* p);

	void setBuilder(PlantBuilder* p);

	void construct();
};

#endif
