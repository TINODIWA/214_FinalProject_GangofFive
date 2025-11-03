#include "Director.h"
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
#include "GardenPlot.h"
#include "CustomerCare.h"

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

    // delete baseStaff_2;
  // delete baseStaff_3;
  // delete staff_4;
  // delete baseStaff;
  cout << "TESTING GARDEN BUILDER\n";
  Builder* cropBuilder = new CropBuilder();
  BuildPlant* plantBuilder = new PlantBuilder();

  Director dir = Director(cropBuilder, plantBuilder);
  Garden* garden = dir.construct("plants.txt");

  cout << "\n\nGarden Created \n";
  garden->print();

   cout << "TESTING GardenPlot Summary\n\n";

  GardenPlot plot = GardenPlot("plants.txt");

  // cout << "ALL PLANTS" << endl;

  // for (auto p : plot.viewAll()) {
  //   cout << p.first << "\t" << p.second << endl;
  // }

  // cout << "\n AVAILABLE PLANTS" << endl;
  // for (auto p : plot.viewAvailable()) {
  //   cout << p.first << "\t" << p.second << endl;
  // }

  // cout << "\nTESTING GETTING PLANTS FROM THE GARDEN - REMOVE\n" << endl;
  // vector<Garden*> buy = plot.get("Azalea", 4);
  // cout << "Order:\n";

  // for (int i = 0; i < buy.size(); i++) {
  //   if (buy[i]) {
  //     cout << buy[i]->print() << endl;
  //     delete buy[i];
  //   }
  // }

  // cout << "------------------------------------\n";

  // cout << endl;
  // cout << endl;
  // for (auto p : plot.viewAll()) {
  //   cout << p.first << "\t" << p.second << endl;
  // }

  // cout << "\nTESTING GETTING PLANT ADVICE\n" << endl;
  // cout << plot.get("Rosemary")->advice() << endl;

  // cout << "\nTESTING GETTING PA PLANT BY NAME - NO REMOVE\n" << endl;
  // Garden* ptr = plot.get("Oak");

  // if (ptr) cout << "Got " << ptr->print() << endl;
  // else cout <<":(\n";

  cout << "\n==================TESTING CHAIN\n";
  Staff* base = new BaseStaff(nullptr, "Joy");
  Staff* gardener = new Gardening(new BaseStaff(NULL, "Grace"));
  Staff* sales = new Sales(new BaseStaff(NULL, "Peace"));
  Staff* manager = new Management(new BaseStaff(NULL, "Love"));

  Customer* unathi = new Customer("unathi");

  Request req = Request("Enter");

//   Staff* chain = base;
//   base->setSuccessor(gardener);
//   gardener->setSuccessor(sales);
//   sales->setSuccessor(manager);
//   manager->setSuccessor(NULL);
//   chain->handleCustomer(req,unathi);

  Nursery* cc = new CustomerCare(&plot);
  cc->addStaff(base);
  cc->addStaff(gardener);
  cc->addStaff(sales);
  cc->addStaff(manager);

  ((CustomerCare*) cc)->setChain();
  cc->addCustomer(unathi);

// unathi->setNursery(cc);
  unathi->makeReq(req);

  cout << "\n===================Memory Management!!!" << endl;
  delete staff_5;
  delete staff_3;
  delete staff_2;
  delete staff_1;
  delete base;
  delete gardener;
  delete sales;
  delete manager;
  delete unathi;
  delete cc;
  delete garden;
  return 0;
}
