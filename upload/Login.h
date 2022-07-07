#ifndef __Login_h_
#define __Login_h_  

#include <iostream>
#include "database.h"
using namespace std;

class Login : public Database
{
    private: 
        char query[1024];
        string pw;
        string userid;

    public:
        static string id;
        void tryLogin(); 
        void inputLogin(); 

        
};
#endif