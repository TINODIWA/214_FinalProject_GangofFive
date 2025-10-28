/**
 * @file Director.h
 * @author Swelihle Makhathini
 * @brief
 * @version 0.1
 * @date 2025-10-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "Builder.h"
#include "Crop.h"
#include "CropBuilder.h"
#include "PlantInfo.h"

using namespace std;

class Director {
   private:
    CropBuilder *cropBuilder;
    map<string, vector<PlantInfo>> plants;
    vector<string> plantTypes;

   public:
    Director();
    ~Director();
    Director(CropBuilder *p);
    void setBuilder(CropBuilder *p);
    Plant *construct(string filename);
    void parse(string filename);
};

#endif
