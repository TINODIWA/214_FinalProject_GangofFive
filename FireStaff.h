/**
 * @file FireStaff.h
 * @brief Command to fire (remove) a staff member via the Nursery mediator.
 */

#ifndef FIRESTAFF_H
#define FIRESTAFF_H

#include "Command.h"

class FireStaff : public Command {
 public:
  FireStaff(Staff* manager, Nursery* mediator, Staff* firee, const std::string& message = "FireStaff");
  virtual ~FireStaff();
  virtual void execute();

 private:
  Staff* firee;
};

#endif // FIRESTAFF_H
