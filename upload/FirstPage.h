#ifndef __FIRSTPAGE_h_
#define __FIRSTPAGE_h_  

#include <iostream>
#include "database.h"
using namespace std;

class FirstPage : public Database
{
    private:
        char query[1024];
        int input;
    public:
        void showMenu();
};
#endif