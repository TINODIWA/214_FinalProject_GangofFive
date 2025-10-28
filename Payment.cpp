#include "Payment.h"

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
string Payment::purchase(Customer *customer, map<Plant*,int> plants, Staff *staff)
{
    prepare();
    payment();
    return receipt(customer, plants, staff);
}

string Payment::receipt(Customer *customer, map<Plant*,int> plants, Staff *staff)
{
    stringstream receipt;

    receipt << "Customer Copy\n";
    receipt << "---------------------------";
    receipt << staff->getName() << "\n";
    receipt << "Customer: " << customer->getName() << "\n";
    receipt << "---------------------------";
    receipt<<"Payment Method: "<<getType()<<"\n";
    receipt<<"Order:\n";

    map<Plant*,int>::iterator it = plants.begin();
    while(it != plants.end()){
        receipt << (*it).first->getName();
        receipt <<right<<setw(10)<<"R"<<(*it).first->getPrice()<<"\n";
    }

    return receipt.str();
}
