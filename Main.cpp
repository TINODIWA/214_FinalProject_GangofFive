/**
 * @file TestingMain.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Builder.h"
#include "Card.h"
#include "Cash.h"
#include "CropBuilder.h"
#include "PlantBuilder.h"
#include "Customer.h"
#include "Director.h"
#include "EFT.h"
#include "Nursery.h"
#include "Order.h"
#include "Payment.h"
#include "People.h"
#include "Plant.h"
#include "Request.h"
#include "Staff.h"
#include "Sales.h"
#include "Gardening.h"
#include "Admin.h"
#include "Management.h"
#include "BaseStaff.h"

#include <map>
#include <iostream>
#include <vector>
#include "BuildPlant.h"

int main() {
    cout << "\n\nTESTING DECORATOR\n";
    Staff* baseStaff = new BaseStaff(nullptr, "Nathan");
    cout << baseStaff->getName() << "\n" << baseStaff->getType() << "\n" << baseStaff->jobDesc() << endl;

    Staff* staff_1 = new Sales(baseStaff);
    cout << endl;
    cout << staff_1->getName() << "\n" << staff_1->getType() << "\n" << staff_1->jobDesc() << endl;

    Staff* baseStaff_2 = new BaseStaff(nullptr, "Unathi");
    cout << baseStaff_2->getName() << "\n" << baseStaff_2->getType() << "\n" << baseStaff_2->jobDesc() << endl;

    Staff* staff_2 = new Admin(baseStaff_2);
    cout << endl;
    cout << staff_2->getName() << "\n" << staff_2->getType() << "\n" << staff_2->jobDesc() << endl;

    Staff* baseStaff_3 = new BaseStaff(nullptr, "Dominiqu");
    cout << baseStaff_3->getName() << "\n" << baseStaff_3->getType() << "\n" << baseStaff_3->jobDesc() << endl;

    Staff* staff_3 = new Management(baseStaff_3);
    cout << endl;
    cout << staff_3->getName() << "\n" << staff_3->getType() << "\n" << staff_3->jobDesc() << endl;

    Staff* staff_4 = new BaseStaff(nullptr, "Swey");
    cout << staff_4->getName() << "\n" << staff_4->getType() << "\n" << staff_4->jobDesc() << endl;

    Staff* staff_5 = new Gardening(staff_4);
    cout << endl;
    cout << staff_5->getName() << "\n" << staff_5->getType() << "\n" << staff_5->jobDesc() << endl;

    delete staff_5;
    delete staff_3;
    delete staff_2;
    delete staff_1;
    delete baseStaff_2;
    delete baseStaff_3;
    delete baseStaff;
  cout << "TESTING GARDEN BUILDER\n";
  Builder* cropBuilder = new CropBuilder();
  BuildPlant* plantBuilder = new PlantBuilder();

  Director dir = Director(cropBuilder, plantBuilder);
  Garden* garden = dir.construct("plants.txt");

  cout << "\n\nGarden Created \n";
  garden->print();

  // cout << "TESTING ORDER TEMPLATE METHOD\n";

  // Payment* eft = new EFT();
  // map<Plant*, int> order_1;

  // Plant* acacia = new Tree();
  // acacia->setName("Acacia");
  // acacia->setType("Tree");
  // acacia->setPrice(20);

  // Plant* lavender = new Shrub();
  // lavender->setName("Lavender");
  // lavender->setType("Shrub");
  // lavender->setPrice(5);

  // order_1[acacia] = 2;
  // order_1[lavender] = 3;

  // Staff* teller_1 = new Staff("Maggie");
  // Customer* c1 = new Customer("Dom");

  // string order_receipt = eft->purchase(c1, order_1, teller_1);
  // cout << order_receipt << endl;

  // delete eft;
  // delete acacia;
  // delete lavender;
  // delete teller_1;
  // delete c1;

  return 0;
}
