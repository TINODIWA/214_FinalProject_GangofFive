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
Director::Director() : cropBuilder(nullptr) {}

/**
 * @brief Destroy the Director:: Director object
 *
 */
Director::~Director() {
    if (cropBuilder) {
        delete cropBuilder;
        cropBuilder = nullptr;
    }
}

/**
 * @brief Construct a new Director:: Director object
 *
 * @param p plant builder
 */
Director::Director(CropBuilder *p) : cropBuilder(p) {}

/**
 * @brief sets the plant builder to a new one
 *
 * @param p
 */
void Director::setBuilder(CropBuilder *p) {
    if (cropBuilder) {
        delete cropBuilder;
        cropBuilder = nullptr;
    }

    cropBuilder = new CropBuilder(p);
}

/**
 * @brief build the garden of crops
 *
 */
Plant *Director::construct(string filename) {
    cropBuilder->reset();
    parse(filename);

    map<string, vector<PlantInfo>>::iterator it = plants.begin();
    bool crop = true;
    while (it != plants.end()) {
        cropBuilder->addCrop((*it).first);  //

        vector<PlantInfo>::iterator p_it = (*it).second.begin();
        while (p_it != (*it).second.end()) {
            cropBuilder->addPlant(*p_it);
            ++p_it;
        }

        ++it;
    }

    return cropBuilder->getCrop();
}

/**
 * @brief gets user input for the garden
 *
 */

void Director::parse(string filename) {
    fstream infos(filename);
    if (infos.is_open()) {
        string line;
        while (getline(infos, line)) {
            stringstream ss(line);
            string token;
            int i = 0;

            PlantInfo p = PlantInfo();

            while (getline(ss, token, '#')) {
                switch (i) {
                    case 0:  // type
                        p.setType(token);
                        break;
                    case 1:  // name
                        p.setName(token);
                        break;
                    case 2:  // amount
                        p.setAmount(stoi(token));
                        break;
                    case 3:  // water
                        p.setWater(stoi(token), 1);
                        break;
                    case 4:  // sun
                        p.setSun(stoi(token), 1);
                        break;
                    case 5:  // fertiliser
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