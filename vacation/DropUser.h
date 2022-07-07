#ifndef __DROPUSER_h_
#define __DROPUSER_h_  

#include <iostream>
#include "database.h"
#include "Login.h"
using namespace std;

class DropUser : public Database
{
    private: 
        char query[1024];
        string line;
        string out; 
    public:
        void byebye(); 
        void execDrop();
        void saveDrop();
        void deleteResrv();
};
#endif