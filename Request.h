/**
 * @copyright Copyright (c) 2025
 *
 */

#ifndef REQUEST_H_
#define REQUEST_H_

#include <iostream>
#include <string>

using namespace std;

class Request {
 private:
  int id;
  string description;

 public:
  Request();

  string getRequest();
};

#endif  // REQUEST_H_
