#ifndef __RESERV_h_
#define __RESERV_h_  

#include <iostream>
#include "database.h"
using namespace std;

class Reserv : public Database
{
    private:
        char query[1024];
        string input;
        int coursenum;
        string stayname;
        string guid;
        string date;
        string id; //임시로 

    public:
        void startReserv();//예약시작  
        void showCourse(); //코스 보여줌 ok
        void selectCourse(); //코스 선택 
        void showStay();//숙소 보여줌 ok
        void selectStay(); //숙소 선택 
        void requestGuid(); // 가이드 요청
        void regitReserv(); //db에 정보 등록
};

#endif