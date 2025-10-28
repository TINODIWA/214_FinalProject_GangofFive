#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>

using namespace std;

class Request {

private:
	int id;
	string description;

public:
	Request();

	string getRequest();
};

#endif
