/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Builder.h"
#include "CropBuilder.h"
#include "Director.h"

int main() {
  cout << "TESTING GARDEN BUILDER\n";
  CropBuilder* cropBuilder = new CropBuilder();

  Director dir = Director(cropBuilder);
  Plant* garden = dir.construct("plants.txt"); ////ROOT

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
