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

  cout << "\n==================TESTING CHAIN\n";
  Staff* base = new BaseStaff(nullptr, "Joy");
  Staff* gardener = new Gardening(new BaseStaff(NULL, "Grace"));
  Staff* sales = new Sales(new BaseStaff(NULL, "Peace"));
  Staff* manager = new Management(new BaseStaff(NULL, "Love"));


  Request req = Request("HIIIII");

  Staff* chain = base;
  base->setSuccessor(gardener);
  gardener->setSuccessor(sales);
  sales->setSuccessor(manager);
  manager->setSuccessor(NULL);

  chain->handleCustomer(req);

  cout << "\n===================Memory Management!!!" << endl;
  delete staff_5;
  delete staff_3;
  delete staff_2;
  delete staff_1;
  delete base;
  delete gardener;
  delete sales;
  delete manager;
  return 0;
}
