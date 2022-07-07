#ifndef __USERMANAGEMENT_H_
#define __USERMANAGEMENT_H_
#include "database.h"

class user_management : public Database
{
    private:
        std::string user_id;
    public:
        void show_user_list();
        void show_delete_user_list();
        void delete_user();
        void change_user_grade();  
};
#endif