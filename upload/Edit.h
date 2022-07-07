#ifndef __EDIT_h_
#define __EDIT_h_  

#include <iostream>
#include "database.h"
#include "Reserv.h"
#include "Login.h"
using namespace std;

class Edit : public Reserv 
{
    private:
        char query[1024];
        string input;
        int select;
        int num;
        //int coursenum;
        string coursename;
       // string stayname;
       // string guid;
       // string date;
       // string id; //임시로
    public:
        void checkReserv();
        
        void reservMenu();
        void guidMenu();
        void stayMenu();
        void changeReserv();
        void changeStay();
        void changeGuid();
        void changeCourse();

        void selectReserv(); 
        void requestGuid();
        
        void cancelMenu();
        void cancelStay();
        void cancelGuid();
        void cancelCourse();
        
};
#endif