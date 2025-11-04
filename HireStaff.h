/**
 * @file HireStaff.h
 * @brief Command to hire (add) a staff member via the Nursery mediator.
 */

#ifndef HIRESTAFF_H
#define HIRESTAFF_H

#include "Command.h"

class HireStaff : public Command {
 public:
  HireStaff(Staff* manager, Nursery* mediator, Staff* hiree, const std::string& message = "HireStaff");
  virtual ~HireStaff();
  virtual void execute();

 private:
  Staff* hiree;
};

#endif // HIRESTAFF_H
