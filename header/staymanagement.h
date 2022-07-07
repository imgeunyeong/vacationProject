#ifndef __STAYMANAGEMENT_H_
#define __STAYMANAGEMENT_H_
#include "database.h"
#include <string>

class stay_management : public Database
{
     private:
        std::string stay_name;
        std::string stay_address;
    public:
        void show_stay_list();
        void delete_stay();
        void append_stay();
        void change_stay();   
};
#endif