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

  cout << "ALL PLANTS" << endl;

  for (auto p : plot.viewAll()) {
    cout << p.first << "\t" << p.second << endl;
  }

  cout << "\n AVAILABLE PLANTS" << endl;
  for (auto p : plot.viewAvailable()) {
    cout << p.first << "\t" << p.second << endl;
  }

  cout << "\nTESTING GETTING PLANTS FROM THE GARDEN - REMOVE\n" << endl;
  vector<Garden*> buy = plot.get("Azalea", 4);
  cout << "Order:\n";

  for (int i = 0; i < buy.size(); i++) {
    if (buy[i]) {
      cout << buy[i]->print() << endl;
      delete buy[i];
    }
  }

  cout << "------------------------------------\n";

  cout << endl;
  cout << endl;
  for (auto p : plot.viewAll()) {
    cout << p.first << "\t" << p.second << endl;
  }

  cout << "\nTESTING GETTING PLANT ADVICE\n" << endl;
  cout << plot.get("Rosemary")->advice() << endl;

  cout << "\nTESTING GETTING PA PLANT BY NAME - NO REMOVE\n" << endl;
  Garden* ptr = plot.get("Oak");

  if (ptr) cout << "Got " << ptr->print() << endl;
  else cout <<":(\n";

  cout << "\n==================TESTING CHAIN\n";
  Staff* base = new BaseStaff(nullptr, "Joy");
  Staff* gardener = new Gardening(new BaseStaff(NULL, "Grace"));
  Staff* sales = new Sales(new BaseStaff(NULL, "Peace"));
  Staff* manager = new Management(new BaseStaff(NULL, "Love"));
  Staff* admin = new Admin(new BaseStaff(NULL, "Faith"));

  Customer* unathi = new Customer("unathi");
  Customer* swey = new Customer("Swey");

  Request req = Request("Enter");

  // Staff* chain = base;
  // base->setSuccessor(gardener);
  // gardener->setSuccessor(sales);
  // sales->setSuccessor(manager);
  // manager->setSuccessor(NULL);
  // chain->handleCustomer(req,unathi);

  Nursery* cc = new CustomerCare(&plot);
  cc->addStaff(base);
  cc->addStaff(gardener);
  cc->addStaff(sales);
  cc->addStaff(manager);

  ((CustomerCare*)cc)->setChain();
  cc->addCustomer(unathi);
  cc->addCustomer(swey);

  // unathi->setNursery(cc);
  unathi->makeReq(req);
  Plant* plant = new Plant();
  Order* order = new Order();
  order->addPlant(plant);
  order->setCustomer(swey);;
  order->setStaff(sales);
  order->purchase(0);
  swey->addOrder(order);

  swey->makeReq(req);

  StaffCo_ordination staffCoord(&plot);
  staffCoord.addStaff(base);
  staffCoord.addStaff(gardener);
  staffCoord.addStaff(sales);
  staffCoord.addStaff(manager);
  staffCoord.addStaff(admin);

  cout << "\n-- Broadcast: Gardener reports dead plant (PlantDeadReport) --\n";
  gardener->send("Detected dead plant in section A", manager, &staffCoord, "PlantDeadReport");

  cout << "\n-- Direct: Manager -> Admin (CheckInventory) --\n";
  manager->send("Please check inventory now", admin, &staffCoord, "CheckInventory");

  cout << "\n-- Commands: Management assigns tasks (CheckInventory, CheckPlant) --\n";
  if (auto mgmt = dynamic_cast<Management*>(manager)) {
    mgmt->assignTasks(&staffCoord);
  }

  cout << "\n-- Commands: Hire and Fire staff via Management --\n";
  Staff* tempBase = new BaseStaff(&staffCoord, "TempWorker");
  Staff* tempRole = new Gardening(tempBase);
  if (auto mgmt = dynamic_cast<Management*>(manager)) {
    mgmt->hireStaff(tempRole);
    for(Staff* s : staffCoord.getStaff()) {
      cout << "  Current staff: " << s->getName() << " [" << s->getType() << "]\n";
    }
    cout << endl;
    mgmt->fireStaff(tempRole);
    for(Staff* s : staffCoord.getStaff()) {
      cout << "  Current staff: " << s->getName() << " [" << s->getType() << "]\n";
    }
  }
  // Defer deletion of tempRole until after all mediator interactions are done.
  // Do NOT delete tempBase separately; the decorator (tempRole) owns and deletes it.

  cout << "\n-- Broadcast: Manager daily announcement --\n";
  manager->send("Daily plant care checks, please.", &staffCoord, "Announcement");

  cout << "\n===================Memory Management!!!" << endl;
  // Clean up temporary role (also deletes its wrapped BaseStaff)
  delete tempRole;
  delete staff_5;
  delete staff_3;
  delete staff_2;
  delete staff_1;
  delete base;
  delete gardener;
  delete sales;
  delete admin;
  delete manager;
  delete unathi;
  delete cc;
  delete garden;
  // delete plant;
  // delete order;
  delete swey;
  return 0;
}
