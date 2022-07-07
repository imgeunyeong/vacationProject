#ifndef __TOURISTMANAGEMENT_H_
#define __TOURISTMANAGEMENT_H_
#include "database.h"

class tourist_management : public Database
{
    private:
        int tourist_num;
        std::string tourist_name;
    public:
        void show_tourist();
        void delete_tourist();
        void append_tourist();
        void change_tourist();
};
#endif