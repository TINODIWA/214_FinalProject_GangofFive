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
map<string, int> GardenPlot::viewAll() {
  if (!garden) return {};
  map<string, int> all;
  return garden->summary(all);
}
map<string, int> GardenPlot::viewAvailable() {
  Iterator* it = garden->createIterator();
  int PlantCount = 0;
  string type = "";
  map<string, int> all;

  while (!it->done()) {
    map<string, int> plant = (**it)->summary(all);
    if (plant.empty() && ((**it)->getState() != "Dying" || (**it)->getState() != "Dead")) {
      type = (type == "") ? (**it)->print() : type;
      ++PlantCount;
    } else {
      if (type != "") all[type] = PlantCount;
    }

    ++(*it);
  }
  delete it;

  if (type != "") all[type] = PlantCount;
  return all;
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
 * @brief returns a vector of num of the passed in plants
 *
 */
vector<Garden*> GardenPlot::get(string name, int num) {
  if (!garden) {
    return {};
  }

  return garden->get(name, num);
}
/**
 * @brief return advice on how to care for the passed in plant
 *
 */
string GardenPlot::getAdvice(string name) {
  return garden->getAdvice(name);
}
