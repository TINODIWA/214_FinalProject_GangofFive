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
 * @brief Construct a new Command object
 * @param s Staff sending the command
 * @param m Staff coordination pointer for the command to go to correct ConcreteMediator
 * @param message The message to be sent with the command
 * @param cmdType The type of command being sent
 */
Command::Command(Staff* s, Nursery* m, string message, string cmdType) : from(s), mediator(m), msg(message), commandType(cmdType) {}

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
