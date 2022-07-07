#ifndef __SHOWMENU_H_
#define __SHOWMENU_H_
#include "nomaluser.h"
#include "touristmanagement.h"
#include "guidemanagement.h"
#include "reservationmanagement.h"
#include "staymanagement.h"
#include "usermanagement.h"

class showmenu
{
    private:
        int select;
        nomaluser user;
        tourist_management tour;
        guide_management guide;
        reservation_management reservation;
        stay_management stay;
        user_management manageuser;
    public:
        void nomaluser_show_main();
        void nomaluser_show_select();
        void server_show_menu();
        void server_show_manage_menu();
        void server_show_tourist_menu();
        void server_show_stay_menu();
        void server_show_guide_menu();
};
#endif