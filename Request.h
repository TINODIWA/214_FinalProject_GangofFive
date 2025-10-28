#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class Request {
   private:
    int id;
    string description;

   public:
    Request();

    string getRequest();
};

#endif
