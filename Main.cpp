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

  GardenPlot* plot = new GardenPlot("plants.txt");
  Nursery* staff = new StaffCo_ordination(plot);
  Nursery* customer = new CustomerCare(plot);  // assuming chain of responsibility is instantiated here

  // instantiate staff
  Staff* baseStaff = new BaseStaff(nullptr, "Nathan");
  Staff* staff_1 = new Sales(baseStaff);

  Staff* baseStaff_2 = new BaseStaff(nullptr, "Unathi");
  Staff* staff_2 = new Admin(baseStaff_2);

  Staff* baseStaff_3 = new BaseStaff(nullptr, "Dominiqu");
  Staff* staff_3 = new Management(baseStaff_3);

  Staff* staff_4 = new BaseStaff(nullptr, "Swey");
  Staff* staff_5 = new Gardening(staff_4);

  staff->addStaff(staff_1);
  staff->addStaff(staff_2);
  staff->addStaff(staff_3);
  staff->addStaff(staff_4);

  customer->addStaff(staff_1);
  customer->addStaff(staff_2);
  customer->addStaff(staff_3);
  customer->addStaff(staff_4);

  int days = 0;
  bool sim = true;
  while (sim) {
    int numCustomer = rand() % 9;
    for (int i = 0; i < 8; i++) {
      // plot.transpire(/*decreasedLevel*/0);
      // gardener.checkPlant();
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

  delete plot;
  delete staff;
  delete customer;

  return 0;
}
