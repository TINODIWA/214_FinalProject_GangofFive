/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CUSTOMERCARE_H_
#define CUSTOMERCARE_H_

#include <iostream>
#include <string>

#include "People.h"
#include "Nursery.h"

class CustomerCare : public Nursery {
  public:
    CustomerCare();
    void notify();
    void setColleague(Nursery* n, People* p);
    
  private:
    People* chatList;
};

#endif  // CUSTOMERCARE_H_
