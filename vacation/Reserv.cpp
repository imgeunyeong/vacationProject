#include <iostream>
#include "database.h"
#include "search.h"
#include "Reserv.h"
#include "Login.h"
using namespace std;

void search::showSpot()
{
    sprintf(query, "SELECT * FROM spot"); 
    mysql_query(&conn, query); 
    result = mysql_store_result(&conn); 
    while(row = mysql_fetch_row(result))
        cout<<"<코스"<<row[0]<<">"<<" "<<row[1]<<endl;
}

void Reserv::startReserv()
{
    cout<<"예약을 시작합니다"<<"\n"<<"\n";
    selectCourse();
    selectStay();
    cout<<"가이드를 요청 하시겠습니까(y/n)"<<endl;
    cin>>guid;
    //requestGuid();
    cout<<"출발 날짜를 정해주세요"<<endl;
    cin>>date;
    cout<<"예약이 완료 되었습니다"<<endl;
    regitReserv();
}

void Reserv::showCourse()
{
    sprintf(query, "SELECT * FROM spot"); 
    mysql_query(&conn, query);
    result = mysql_store_result(&conn); 
    while(row = mysql_fetch_row(result))
        cout<<"<코스"<<row[0]<<">"<<" "<<row[1]<<endl;
}

void Reserv::selectCourse() 
{   
    Reserv::showCourse();
    while(1)
    {    
        cout<<"코스를 골라주세요"<<endl;
        cin>>coursenum;
        sprintf(query, "SELECT coursenum FROM spot WHERE coursenum='%d'",int(coursenum));
        mysql_query(&conn, query);
        result = mysql_store_result(&conn);
        if ((row = mysql_fetch_row(result)) == NULL)
            cout << "목록에 없습니다 다시 골라주세요" << endl;
        else break;
    }
}

void Reserv::showStay()
{
    sprintf(query, "SELECT * FROM stay"); 
    mysql_query(&conn, query);
    result = mysql_store_result(&conn); 
    while(row = mysql_fetch_row(result))
        cout<<"숙소명: "<<row[0]<<" "<<"주소: "<<row[1]<<endl;
}

void Reserv::selectStay() 
{   
    Reserv::showStay();
    while(1)
    {
        cout<<"숙소를 골라주세요"<<endl;
        cin>>stayname;
        sprintf(query, "SELECT stayname FROM stay WHERE stayname='%s'", stayname.c_str());
        mysql_query(&conn, query);
        result = mysql_store_result(&conn);
        if ((row = mysql_fetch_row(result)) == NULL)
        {
            cout << "목록에 없습니다 다시 골라주세요" << endl;
            continue;
        }
        else break;
    }
}

void Reserv::requestGuid()
{   
        if(guid !="y"|| guid !="n")
            cout<<"제대로 입력해주세요"<<endl;
}

void Reserv::regitReserv()
{   
    sprintf(query,"SELECT stand FROM spot WHERE coursenum = '%d'",coursenum);
    mysql_query(&conn, query);
    result = mysql_store_result(&conn);
    row = mysql_fetch_row(result);
    sprintf(query, "INSERT INTO reservation (id,coursenum,coursecontent,stayname,guid,date) VALUES ('%s', '%d','%s','%s','%s','%s')",Login::id.c_str(),coursenum,row[0],stayname.c_str(),guid.c_str(),date.c_str());
    mysql_query(&conn, query);
}