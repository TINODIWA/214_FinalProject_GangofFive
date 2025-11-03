/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef STAFF_H_
#define STAFF_H_

#include <string>
#include <vector>

#include "People.h"
#include "Request.h"

class Plant;

class Staff : public People{
  protected:
    Staff *successor;

  public:
    Staff();
    Staff(Nursery* n, string name);
    Staff(const Staff *other);
    ~Staff();
    
    virtual std::string jobDesc() = 0;
    virtual std::string getType() = 0;
    virtual void update(Plant *p) = 0;
    virtual void handlePlant(Plant *p) = 0;
    virtual void handleCustomer(Request *req);
    virtual void receive(string m, People* from, Nursery* group, string type) = 0;
    
    void setSuccessor(Staff *succ);

    bool operator==(const Staff& other) const;
};

#endif  // STAFF_H_
