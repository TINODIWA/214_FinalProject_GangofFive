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
#include "BuildPlant.h"

#include <map>
#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
  Director dir = Director(new CropBuilder(), new PlantBuilder());

  GardenPlot plot = GardenPlot("plants.txt");
  Nursery* staff = new StaffCo_ordination(&plot);
  Nursery* customer = new CustomerCare(&plot);  // assuming chain of responsibility is instantiated here

  // instantiate staff
  Staff* base = new BaseStaff(nullptr, "BaseStaff Ryan");

  Staff* baseStaff = new BaseStaff(nullptr, "Nathan");
  Staff* sales = new Sales(baseStaff);

  Staff* baseStaff_2 = new BaseStaff(nullptr, "Unathi");
  Staff* admin = new Admin(baseStaff_2);

  Staff* baseStaff_3 = new BaseStaff(nullptr, "Dominiqu");
  Management* management = new Management(baseStaff_3);

  Staff* staff_4 = new BaseStaff(nullptr, "Swey");
  Gardening* gardener = new Gardening(staff_4);

  Customer* alice = new Customer("Alice");
  Customer* bob = new Customer("Bob");

  staff->addStaff(base);
  staff->addStaff(sales);
  staff->addStaff(admin);
  staff->addStaff(management);
  staff->addStaff(gardener);

  Request req = Request("Enter");
  
  customer->addStaff(base);
  customer->addStaff(sales);
  customer->addStaff(admin);
  customer->addStaff(management);
  customer->addStaff(gardener);
  ((CustomerCare*)customer)->setChain();

  // customer->addCustomer(alice);
  // customer->addCustomer(bob);
  int days = 0;
  bool sim = true;
  while (sim) {
    int numCustomer = rand() % 9;
    for (int i = 0; i < 8; i++) {
      management->assignTasks(staff);
      
      plot.transpire(0);
      gardener->checkPlants();
      if (i % numCustomer == 0) {
        Customer* c = new Customer("Customer_" + to_string(i));
        customer->addCustomer(c);
        c->makeReq(Request("Enter"));
      }
    }
    ++days;

    //   //should we do some restoking here
    //   // iterate through the garden and restock plants.
    //   // we would have to compare to the original parsed file
    //   // maybe some to staff communication chat

    //   // delete plot
    //   // delete staff
    //   // delete customer
    //   // delete instantiated staff
  }

  // delete plot;
  delete staff;
  delete customer;

  return 0;
}
