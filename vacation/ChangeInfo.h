#ifndef __CHANGEINFO_h_
#define __CHANGEINFO_h_  

#include <iostream>
#include "database.h"
#include "Login.h"
using namespace std;

class ChangeInfo : public Database
{
    private: 
        char query[1024];
        int select;
        string input;

    public:
        void showMenu();
        void changeName(); 
        void changePW(); 

};
#endif