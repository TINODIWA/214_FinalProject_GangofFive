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
 *
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
  cropBuilder->reset();

  // Parse the file

  fstream plants(filename);
  if (!plants.is_open()) {
    return nullptr;
  }

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

    vector<int> days = {stoi(pieces[6]), stoi(pieces[7])};

    plantBuilder->setDays(days)->setPrice(stoi(pieces[8]));
    Garden* p = plantBuilder->build();

    cropBuilder->add(p);

    for (int i = 0; i < amount - 1; i++) {
      cropBuilder->add(p->clone());
    }
  }

  return cropBuilder->getCrop();
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
