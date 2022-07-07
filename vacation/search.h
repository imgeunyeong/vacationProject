#ifndef __SEARCH_h_
#define __SEARCH_h_  

#include <iostream>
#include "database.h"
using namespace std;

class search : public Database
{
    private: 
        char query[1024];
        string input; //검색할때 변수

    public:
        void showSpot(); //리스트업
        void searchSpot(); //조회
};
#endif