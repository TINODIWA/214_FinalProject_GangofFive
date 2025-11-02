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

#include <map>
#include <iostream>
#include <vector>
#include "BuildPlant.h"

int main() {
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
