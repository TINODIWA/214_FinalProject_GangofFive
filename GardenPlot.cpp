/**
 * @file GardenPlot.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-11-02
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "GardenPlot.h"

/**
 * @brief Construct a new Garden Plot:: Garden Plot object
 *
 */
GardenPlot::GardenPlot() : garden(nullptr) {}

/**
 * @brief Construct a new Garden Plot:: Garden Plot object
 *
 * @param filename
 */
GardenPlot::GardenPlot(string filename) {
  Director dir = Director(new CropBuilder(), new PlantBuilder());
  garden = dir.construct(filename);
}

/**
 * @brief Destroy the Garden Plot:: Garden Plot object
 *
 */
GardenPlot::~GardenPlot() {
  if (garden) {
    delete garden;
    garden = nullptr;
  }
}

/**
 * @brief a summaries view of all the plants in the garden
 *
 * @return string
 */
string GardenPlot::viewAll() {
  if (!garden) return "Please create your garden first.\n";
  return "All Plants in Garden\n" + garden->summary();
}
string GardenPlot::viewAvailable() {
  Iterator* it = garden->createIterator();
  int PlantCount = 0;
  string type = "";
  string sum = "";

  while (!it->done()) {
    string plant = (**it)->summary();
    if (plant == "" && (((**it)->getState() != "Dying") || (**it)->getState() != "Dead")) {
      type = (type == "") ? (**it)->print() : type;
      ++PlantCount;
    } else {
      sum += plant;
    }

    ++(*it);
  }
  delete it;

  string line = (type != "") ? type + to_string(PlantCount) + "\n" : "";
  sum = line + sum;

  return "Plants Available for Sale\n" + sum;
}

/**
 * @brief simulates transpirations of plants
 *
 * @param decreasedLevel
 */
void GardenPlot::transpire(int decreasedLevel) {
  Iterator* it = garden->createIterator();

  while (!it->done()) {
    (**it)->transpire(decreasedLevel);
    ++(*it);
  }
  delete it;
}

/**
 * @brief
 *
 */
Garden* GardenPlot::get(int id, int num) {
    Iterator* it = garden->createIterator();

    while(!it->done()){
        if((**it)->operator==(id)){
            return (**it);
        }

        ++(*it);
    }

    delete it;
}
