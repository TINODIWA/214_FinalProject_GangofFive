/**
 * @file Gardening.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Gardening.h"
#include "Request.h"
#include <iostream>
#include <algorithm>
#include "Plant.h"
#include "Crop.h"
#include <functional>

/**
 * @brief Construct a new Gardening object.
 */
Gardening::Gardening(Staff* s) : Roles(s->getNursery(), s->getName(), s) {}

Gardening::~Gardening() {}

/**
 * @brief Get the staff type for this object.
 */
std::string Gardening::getType() {
  return Roles::getType() + ": Gardening";
}

/**
 * @brief Get the job description for this staff role.
 */
std::string Gardening::jobDesc() {
  return Roles::jobDesc() + "\nGardening staff responsible for plant care and maintenance and giving customers advice.";
}

void Gardening::update() {
}

void Gardening::checkPlants() {
    Nursery* med = getNursery();
    if (!med || !med->getGarden()) return;

    Crop* root = dynamic_cast<Crop*>(med->getGarden());
    if (!root) return;

    std::function<void(Crop*)> traverse = [&](Crop* c){
        if (!c) return;
        Iterator* it = c->createIterator();
        if (!it) return;
        for (Garden* g = it->first(); !it->done(); g = it->next()) {
            if (!g) continue;
            if (Plant* p = dynamic_cast<Plant*>(g)) {
                std::string state = p->getState();
                if (state == "Dead") {
                    Staff* mgmt = med->findStaffByType("BaseStaff: Management");
                    std::string msg = "Plant '" + p->getName() + "' has died";
                    if (mgmt) send(msg, mgmt, med, "PlantDeadReport");
                } else if (state == "Dying") {
                    this->handlePlant(p);
                }
            } else if (Crop* sub = dynamic_cast<Crop*>(g)) {
                traverse(sub);
            }
        }
        delete it;
    };

    traverse(root);
}

void Gardening::handleCustomer(Request* req) {
  if (req->getRequest() == "Advice") {
    std::cout << ". I am " + name +
                     " and I will be assisting you.\n nursery->getGarden()->viewAll() \n\tPlease "
                     "enter the number of the plant you'd like advice on below.\n\t Number:"
              << std::endl;
    int plantId;
    cin >> plantId;

    while (plantId < 1 || plantId > 5) {
      cout << "\n\t nursery->getGarden()->viewAll() \n Please enter a valid number: " << endl;
      cin >> plantId;
    }

    cout << "Plant advice of garden.getAdvice().... \n Would you like: 1)Advice on another plant.\n\t2)Create an "
            "order.\n\t3)Return an old "
            "order\n\t4)Repurchase an old order. \n Please enter a number: ";

    int request;
    cin >> request;

    string pass = "Passing your request on...";
    switch (request) {
      case 1:
        cout << "Plant advice of garden.getAdvice()...." << endl;
        break;
      case 2:
        cout << pass << endl;
        ((CustomerCare*)nursery)->notify(new Request("Order"));
        break;
      case 3:
        cout << pass << endl;
        ((CustomerCare*)nursery)->notify(new Request("Return"));
        break;
      case 4:
        cout << pass << endl;
        ((CustomerCare*)nursery)->notify(new Request("Repurchase"));
        break;
      default:
        cout << "Error in request case switch!" << endl;
        break;
    }
  } else if (successor) {
    successor->handleCustomer(req);
  } else {
    std::cout << "No staff could handle the request." << std::endl;
  }
}

void Gardening::handlePlant(Plant* p) {
    if (!p) return;
    vector<int> w = p->getWater();
    if (w.size() >= 2) {
        // p->plantCare();
        std::cout << getName() << " watered '" << p->getName() << "'" << std::endl;
    }
}

void Gardening::receive(string m, People* from, Nursery* group, string type) {
  if (!(from && group)) return;

  if (dynamic_cast<Staff*>(from)->getType() == "Manager" && group->getName() == "StaffCo_ordination") {
    if (type == "CheckPlants") {
      this->checkPlants();
    }
  }
}

