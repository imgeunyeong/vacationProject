#ifndef __NOMALUSER_H_
#define __NOMALUSER_H_
#include "database.h"
#include <string>
#include <unistd.h>

class nomaluser : public Database
{
    private:
        std::string name;
        std::string id;
        std::string pw;
    public: 
        void signup();
        int login();
        void find_id();
        void find_pw();
        void change_pw();
        void delete_information();    
};
#endif