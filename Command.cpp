/**
 * @file Command.cpp
 * @author Nathan Chisadza
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Command.h"

/**
 * @brief Construct a new Command object for Command
 * @param s Staff sending the the command
 * @param m Staff coordination pointer for the command to go to correct ConcreteMediator
 */
Command::Command(Staff* s, StaffCo_ordination* m) : appointed(s), mediator(m) {}

/**
 * @brief Destroy the Command object
 */
Command::~Command() {
  if (appointed) {
    delete appointed;
    appointed = NULL;
  }

  if (mediator) {
    delete mediator;
    mediator = NULL;
  }
}
