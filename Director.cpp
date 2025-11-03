/**
 * @file Director.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Director.h"

/**
 * @brief Construct a new Director:: Director object
 *
 */
Director::Director() : cropBuilder(nullptr), plantBuilder(nullptr) {}

/**
 * @brief Destroy the Director:: Director object
 */
Director::~Director() {
  if (cropBuilder) {
    delete cropBuilder;
    cropBuilder = nullptr;
  }

  if (plantBuilder) {
    delete plantBuilder;
    plantBuilder = nullptr;
  }

}

/**
 * @brief Construct a new Director:: Director object
 *
 * @param p plant builder
 */
Director::Director(Builder* c, BuildPlant* p) : cropBuilder(c), plantBuilder(p) {}

/**
 * @brief sets the crop builder to a new one
 * NOTICE
 * setting the builder will delete any crop held by the precious one
 *
 * @param p
 */
void Director::setBuilder(Builder* c) {
  if (cropBuilder) {
    delete cropBuilder;
    cropBuilder = nullptr;
  }

  cropBuilder = c->clone();
}

/**
 * @brief sets the plant builder to a new one
 * NOTICE
 * setting the builder will delete any crop held by the precious one
 *
 * @param p
 */
void Director::setBuilder(BuildPlant* p) {
  if (plantBuilder) {
    delete plantBuilder;
    plantBuilder = nullptr;
  }

  plantBuilder = p->clone();
}

/**
 * @brief build the garden of crops
 *
 */
Garden* Director::construct(string filename) {
  // Parse the file
  fstream plants;

  try {
    plants.open(filename);
    if (!plants.is_open()) {
      throw std::runtime_error("Error accessing file");
    }

  } catch (const std::exception& err) {
    cout << "ERROR: " << err.what() << endl;

    return nullptr;
  }

  plants.seekg(0, ios::end);
  if (plants.tellg() == 0) {
    cout << "Oops. It looks like your file is empty.\n";
    cout << "Please populate your file with data in the format: \n";
    cout << "Name#Type#amount#water_requirement(integer)#fertiliser_requirement(integer)#\n"
            "required_sun_exposure(integer)#number_of_days_to_start_growing#\n"
            "number_of_days_to_maturity#price#water_care(H/M/L)#\n"
            "sun_care(H/M/L)#fertiliser_care(H/M/L)\n\n With no spaces and a new line after each plant\n";
    cout << "example: Lily#Flower#4#10#18#9#1#2#75#H#M#L\n\n";

    return nullptr;
  }

  plants.seekg(0, ios::beg);

  cropBuilder->reset();
  string line;

  while (getline(plants, line)) {
    cropBuilder->add();

    plantBuilder->reset();
    vector<string> pieces = split(line, '#');


    int amount = stoi(pieces[2]);

    plantBuilder->setName(pieces[0])
        ->setType(pieces[1])
        ->setWater(stoi(pieces[3]))
        ->setSun(stoi(pieces[4]))
        ->setFertiliser(stoi(pieces[5]));

    vector<int> days = {0, stoi(pieces[7])};

    plantBuilder->setDays(days)
        ->setPrice(stof(pieces[8]))
        ->setWaterCare(pieces[9][0])
        ->setSunCare(pieces[10][0])
        ->setFertiliserCare(pieces[11][0]);
    Garden* p = plantBuilder->build();

    cropBuilder->add(p);

    for (int i = 0; i < amount - 1; i++) {
      cropBuilder->add(p->clone());
    }
  }

  return cropBuilder->getCrop()->clone();
}

/**
 * @brief splits the line of a textfile to instantiate a plant
 *
 * @param str
 * @param delim
 * @return vector<string>
 */
vector<string> Director::split(const string str, char delim) {
  vector<string> pieces;
  stringstream ss(str);

  string piece;

  while (getline(ss, piece, delim)) {
    pieces.push_back(piece);
  }

  return pieces;
}
