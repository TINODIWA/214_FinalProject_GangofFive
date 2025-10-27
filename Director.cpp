#include "Director.h"

/**
 * @brief Construct a new Director:: Director object
 *
 */
Director::Director() : cropBuilder(nullptr)
{
}

/**
 * @brief Destroy the Director:: Director object
 *
 */
Director::~Director()
{
	if (cropBuilder)
	{
		delete cropBuilder;
		cropBuilder = nullptr;
	}
}

/**
 * @brief Construct a new Director:: Director object
 *
 * @param p plant builder
 */
Director::Director(CropBuilder *p) : cropBuilder(new CropBuilder(p)) {}

/**
 * @brief sets the plant builder to a new one
 *
 * @param p
 */
void Director::setBuilder(CropBuilder *p)
{
	if (cropBuilder)
	{
		delete cropBuilder;
		cropBuilder = nullptr;
	}

	cropBuilder = new CropBuilder(p);
}

/**
 * @brief build the garden of crops
 *
 */
Plant *Director::construct()
{
	cout << "Director::construct\n";
	cropBuilder->reset();
	parse();

	cout << "Done parsing file\n";

	cout<<"\n\nPRINTING PLANTS VECTOR\n";
	map<string, vector<PlantInfo>>::iterator parsed_it = plants.begin();
	while (parsed_it != plants.end())
	{
		cout << (*parsed_it).first << ":\n";

		vector<PlantInfo>::iterator parsed_2 = (*parsed_it).second.begin();
		while (parsed_2 != (*parsed_it).second.end())
		{
			cout << (*parsed_2).getName() << "\n";
			++parsed_2;
		}
		++parsed_it;
	}

	cout << "\n***********************************\n";

	map<string, vector<PlantInfo>>::iterator it = plants.begin();
	bool crop = true;
	while (it != plants.end())
	{
		cout << "\n**************\nAdding crop: " << ((*it).first) << "\n";
		cropBuilder->addCrop((*it).first); //

		vector<PlantInfo>::iterator p_it = (*it).second.begin();
		while (p_it != (*it).second.end())
		{
			cout << "\tAdding plant: " << (*p_it).getName() << "\n";
			cropBuilder->addPlant(*p_it);
			++p_it;
		}

		++it;
	}

	cropBuilder->getCrop()->print();

	cout<<"=======================================================================\n";
	cout<<"=======================================================================\n";
	return cropBuilder->getCrop();
}

/**
 * @brief gets user input for the garden
 *
 */

void Director::parse()
{
	fstream infos("plants.txt");
	if (infos.is_open())
	{

		string line;
		while (getline(infos, line))
		{
			stringstream ss(line);
			string token;
			int i = 0;

			PlantInfo p = PlantInfo();

			while (getline(ss, token, '#'))
			{
				switch (i)
				{
				case 0: // type
					p.setType(token);
					break;
				case 1: // name
					p.setName(token);
					break;
				case 2: // amount
					p.setAmount(stoi(token));
					break;
				case 3: // water
					p.setWater(stoi(token), 1);
					break;
				case 4: // sun
					p.setSun(stoi(token), 1);
					break;
				case 5: // fertiliser
					p.setFertiliser(stoi(token), 1);
					break;
					// case 6: //days
					// break;
				}

				i++;
			}
			plants[p.getType()].push_back(p);
		}
		infos.close();
	}
}