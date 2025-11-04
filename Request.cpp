/**
 * @file Request.cpp
 * @author Unathi Tshakalisa
 * @brief Implementation of the Request class which encapsulates customer or staff requests in the nursery system
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Request.h"


/**
 * @brief Get the request description
 * @return string The description of the request
 */
string Request::getRequest() {
  return description;
}


/**
 * @brief Construct a new Request object
 * @param description The description of the request
 */
Request::Request(string description) {
  this->description = description;
}
