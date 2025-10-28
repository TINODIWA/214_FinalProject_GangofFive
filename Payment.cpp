#include "Payment.h"
#include "Staff.h"
#include "Plant.h"
#include "Customer.h"

/**
 * @brief Construct a new Payment:: Payment object
 *
 */
Payment::Payment() {}

/**
 * @brief Destroy the Payment:: Payment object
 *
 */
Payment::~Payment() {}

/**
 * @brief processing purchasing an order of plants
 *
 * @return string
 */
string Payment::purchase(Customer *customer, vector<Plant *> plants, Staff *staff)
{
    prepare();
    payment();
    return receipt(customer, plants, staff);
}

string Payment::receipt(Customer *customer, vector<Plant *> plants, Staff *staff)
{
    stringstream receipt;

    receipt << "Customer Copy\n";
    receipt << "---------------------------";
    receipt << staff->getName() << "\n";
    receipt << "Customer: " << customer->getName() << "\n";
    receipt << "---------------------------";
    receipt<<"Payment Method: "<<getType()<<"\n";
    receipt<<"Order:\n";

    vector<Plant*>::iterator it = plants.begin();
    while(it != plants.end()){
        receipt << (*it)->getName();
        receipt <<right<<setw(10)<<"R"<<(*it)->getPrice()<<"\n";
    }
}
