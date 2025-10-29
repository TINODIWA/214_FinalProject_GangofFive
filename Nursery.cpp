/**
 * @file Nursery.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "Nursery.h"
#include "Customer.h"
#include "Staff.h"

Nursery::Nursery() {
    // TODO(user) - implement Nursery::Nursery
    // throw "Not yet implemented";
}

Nursery::~Nursery() {}

Nursery::Nursery(const Nursery &other) {
    vector<vector<Plant *>>::const_iterator otherPlants = (other.plants).begin();
    vector<Customer *>::const_iterator otherCustomer = (other.customers).begin();
    vector<Staff *>::const_iterator otherStaff = (other.staff).begin();

    while (otherPlants != other.plants.end()) {
        vector<Plant *>::const_iterator it = (*otherPlants).begin();
        vector<Plant *> temp;

        while (it != (*otherPlants).end()) {
            temp.push_back((*it)->clone());
        }
        plants.push_back(temp);
    }

    // while(otherCustomer != other.customers.end())
    // customers.push_back(new Customer(*otherCustomer))
}

void Nursery::addPlant(Plant *p) {
    // TODO(user) - implement Nursery::addPlant
    // throw "Not yet implemented";
}

void Nursery::removePlant(Plant *p) {
    // TODO(user) - implement Nursery::removePlant
    // throw "Not yet implemented";
}

void Nursery::start(bool sim) {
    // TODO(user) - implement Nursery::start
    // throw "Not yet implemented";
}

void Nursery::addStaff(Staff *s) {
    // TODO(user) - implement Nursery::addStaff
    // throw "Not yet implemented";
}

void Nursery::removeStaff(Staff *s) {
    // TODO(user) - implement Nursery::removeStaff
    // throw "Not yet implemented";
}

void Nursery::notify() {
    // TODO(user) - implement Nursery::notify
    // throw "Not yet implemented";
}
