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
GardenPlot::GardenPlot(): garden(nullptr){}

/**
 * @brief Construct a new Garden Plot:: Garden Plot object
 * 
 * @param filename 
 */
GardenPlot::GardenPlot(string filename){
    Director dir = Director(new CropBuilder(), new PlantBuilder());
    garden = dir.construct(filename);
}

/**
 * @brief Destroy the Garden Plot:: Garden Plot object
 * 
 */
GardenPlot::~GardenPlot(){
    if (garden){
        delete garden;
        garden = nullptr;
    }
}

/**
 * @brief a summaries view of all the plants in the garden
 * 
 * @return string 
 */
string GardenPlot::viewAll(){
    if(!garden)
        return "Please create your garden first.\n";
    return garden->summary();
}
string GardenPlot::viewAvailable(){}
void GardenPlot::transpire(int decreasedLevel){}
