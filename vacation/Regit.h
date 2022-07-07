#ifndef __Regit_h_
#define __Regit_h_  

#include <iostream>
#include "database.h"
using namespace std;

class Regit : public Database
{
    private:
        char query[1024];
        string id;
        string pw;
        string name;
        string usertype;

    public:
        void signUp();
        void inputInfo();
        void idCheck();


};
#endif