#ifndef __RESERVATIONMANAGEMENT_H_
#define __RESERVATIONMANAGEMENT_H_
#include "database.h"
#include <string>
#include <unistd.h>

class reservation_management : public Database
{
    private:

    public:
        void show_reservation_list();
        void show_delete_reservation_list();
};
#endif