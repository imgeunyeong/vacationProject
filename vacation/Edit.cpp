#include <iostream>
#include "database.h"
#include "Edit.h"
#include <unistd.h>
#include "Login.h"
using namespace std;

void Edit::checkReserv()
{  // id="test";//임시
    cout<<"=== 예약내역 ==="<<endl;
    sprintf(query, "SELECT * FROM reservation WHERE id='%s'",Login::id.c_str());
    mysql_query(&conn, query); 
    result = mysql_store_result(&conn);
    if ((row = mysql_fetch_row(result)) == NULL)
            { 
                cout<<"예약 내역이 없습니다"<<endl;
            }
    else
    {
        sprintf(query, "SELECT * FROM reservation WHERE id='%s'",Login::id.c_str());
        mysql_query(&conn, query); 
        result = mysql_store_result(&conn);
        while (row = mysql_fetch_row(result)) 
        {
            cout << "id: " << row[0] << "\n"<<"코스번호: " << row[1] << "\n"<<"코스: " << row[2] << "\n"<<"숙소명: " <<row[3]<<"\n"<<"가이드 여부: "<<row[4]<<"\n"<<"예약날짜: "<<row[5]<<"\n"<<"예약번호: "<<row[6]<<endl;
            cout<<"-----------------"<<endl;
        }
    }
}

void Edit::reservMenu()
{   
    selectReserv();
    cout<<"1.관광지 변경 2.관광 취소"<<endl;
    cin>>select;
    switch (select)
    {
    case 1:
        changeCourse();
        break;
    case 2:
        cancelCourse();
        break;
    default:
        cout<<"선택지를 제대로 입력해주세요"<<endl;
        break;
    }
}

void Edit::selectReserv() 
{
    checkReserv();
    while(1)
    {
        cout<<"변경할 예약 번호를 입력해주세요"<<endl;
        cin>>num;
        sprintf(query, "SELECT * FROM reservation WHERE reservnum='%d'",num);
            
            if (mysql_query(&conn, query) != 0)
            {
                fprintf(stderr, "Failed to connect to databases: Error: %s\n",mysql_error(&conn));
            }
            result = mysql_store_result(&conn);
            if ((row = mysql_fetch_row(result)) == NULL)
            { 
                cout<<"예약번호를 확인해주세요"<<endl;
                continue;
            }
            else return;
    }

}

void Edit::changeCourse()
{
    Reserv::showCourse();
    while(1)
    {    
       // id="test"; //임시
        cout<<"변경할 코스를 골라주세요"<<endl;
        cin>>select;
        sprintf(query, "SELECT * FROM spot WHERE coursenum='%d'",select);
        
         if (mysql_query(&conn, query) != 0)
        {
            fprintf(stderr, "Failed to connect to databases: Error: %s\n",mysql_error(&conn));
        }
        result = mysql_store_result(&conn);
        if ((row = mysql_fetch_row(result)) == NULL)
        { 
            cout<<"올바른 선택지를 입력해주세요"<<endl;
            continue;
        }
        else
        { 
            sprintf(query, "UPDATE reservation SET coursenum='%d',coursecontent='%s' WHERE reservnum='%d'",select,row[1],num);
            mysql_query(&conn, query);
            result = mysql_store_result(&conn);
            cout<<"변경 완료"<<endl;
            break;
        }
    }
}

void Edit::cancelCourse()
{   
    cout<<". . .예약을 취소합니다"<<endl;
    sleep(1);
    system("clear");

     sprintf(query, "SELECT * FROM reservation WHERE reservnum=%d",num);
     mysql_query(&conn, query);
     result = mysql_store_result(&conn);
     if ((row = mysql_fetch_row(result)) == NULL)
     {cout << "예약 내역이 없습니다" << endl;}

     else
        sprintf(query, "DELETE FROM reservation WHERE reservnum=%d",num);
        if (mysql_query(&conn, query) != 0)
        {
            fprintf(stderr, "Failed to connect to databases: Error: %s\n",mysql_error(&conn));
            cout<<"취소완료"<<endl;
            sleep(1);
        }
}

void Edit::changeStay()
{
    Reserv::showStay();
    while(1)
    {    
       // id="test"; //임시
        cout<<"변경할 숙소를 골라주세요"<<endl;
        cin>>input;
        sprintf(query, "SELECT * FROM stay WHERE stayname='%s'",input.c_str());
        
         if (mysql_query(&conn, query) != 0)
        {
            fprintf(stderr, "Failed to connect to databases: Error: %s\n",mysql_error(&conn));
        }
        result = mysql_store_result(&conn);
        if ((row = mysql_fetch_row(result)) == NULL)
        { 
            cout<<"올바른 선택지를 입력해주세요"<<endl;
            continue;
        }
        else
        { 
            sprintf(query, "UPDATE reservation SET stayname='%s' WHERE reservnum='%d'",row[0],num);
            mysql_query(&conn, query);
            result = mysql_store_result(&conn);
            cout<<"변경 완료"<<endl;
            break;
        }
    }
}
void Edit::cancelStay()
{
    cout<<". . .숙박을 취소합니다"<<endl;
    sleep(1);
    system("clear");

     sprintf(query, "SELECT * FROM reservation WHERE reservnum=%d",num);
     mysql_query(&conn, query);
     result = mysql_store_result(&conn);
     if ((row = mysql_fetch_row(result)) == NULL)
     {cout << "예약 내역이 없습니다" << endl;}

     else
        sprintf(query, "UPDATE reservation SET stayname='%s' WHERE reservnum='%d'","Null",num);
        if (mysql_query(&conn, query) != 0)
        {
            fprintf(stderr, "Failed to connect to databases: Error: %s\n",mysql_error(&conn));
        }
        cout<<"취소완료"<<endl;
}

void Edit::stayMenu()
{    selectReserv();
    cout<<"1.숙소 변경 2.숙박 취소"<<endl;
    cin>>select;
    switch (select)
    {
    case 1:
        Edit::changeStay();
        break;
    case 2:
        Edit::cancelStay();
        break;    
    
    default:
        cout<<"선택지를 제대로 입력해주세요"<<endl;
        break;
    }
}
void Edit::requestGuid()
{
    cout<<". . . 가이드 요청중"<<endl;
    sleep(1);
    system("clear");

     sprintf(query,"UPDATE reservation SET guid='%s' WHERE reservnum='%d'","y",num);
     mysql_query(&conn, query);
     cout<<"요청 성공"<<endl;
}
void Edit::cancelGuid()
{
    cout<<". . . 가이드 취소요청중"<<endl;
    sleep(1);
    system("clear");

     sprintf(query,"UPDATE reservation SET guid='%s' WHERE reservnum='%d'","n",num);
     mysql_query(&conn, query);
     cout<<"취소 완료"<<endl;
}

void Edit::guidMenu()
{   selectReserv();
    cout<<"1.가이드 요청 2.가이드 취소"<<endl;
    cin>>select;
    switch (select)
    {
    case 1:
        requestGuid();
        break;
    case 2:
        cancelGuid();
        break;
    default:
        cout<<"선택지를 제대로 입력해주세요"<<endl;
        break;        
    }
}

void Edit::changeReserv()
{
    cout<<"1.관광지 변경  2.숙소 변경  3.가이드 변경";
    cin>>select;
    switch (select)
    {
    case 1:
        Edit::reservMenu();
        break;
    case 2:
        Edit::stayMenu();
        break;
    case 3:
        Edit::guidMenu();
        break; 
    default:
        cout<<"선택지를 제대로 입력해주세요"<<endl;
        break;
    }
}