#include <iostream>
#include "database.h"
#include "DropUser.h"
#include "Login.h"
using namespace std;

void DropUser::byebye()
{   
    while(1)
    {
        line="탈퇴요청";
        cout<<"정말 회원 탈퇴를 하시려면 아래 탈퇴 문구를 적어주세요"<<endl;
        cout<<line<<endl;
        cout<<"\n";
        cin >>out;
        if(line==out)
        {   
            saveDrop();
            deleteResrv(); //예약내역삭제
            execDrop();
            cout<<"탈퇴가 완료되었습니다"<<endl;
            return;
        }
        else
            cout<<"문구를 정확히 입력해주세요"<<endl;
    }
    
}
void DropUser::execDrop()
{
    sprintf(query, "DELETE FROM usertable WHERE id='%s'",Login::id.c_str());
        if (mysql_query(&conn, query) != 0)
        {
            fprintf(stderr, "Failed to connect to databases: Error: %s\n",mysql_error(&conn));
        }
}
void DropUser::deleteResrv()
{
    sprintf(query, "SELECT * FROM reservation WHERE id='%s'",Login::id.c_str());
    if (mysql_query(&conn, query) != 0)
    {
        fprintf(stderr, "Failed to connect to databases: Error: %s\n",mysql_error(&conn));
    }
    result = mysql_store_result(&conn);
    if ((row = mysql_fetch_row(result)) == NULL) 
    {cout<<"예약한거없음 걍 삭제 ㄱ"<<endl;}
    
    else
        sprintf(query, "DELETE FROM reservation WHERE id='%s'",Login::id.c_str());
        mysql_query(&conn, query);
        
}
void DropUser::saveDrop()
{   
    sprintf(query, "SELECT * FROM usertable WHERE id ='%s'",Login::id.c_str());
    mysql_query(&conn, query); 
    result = mysql_store_result(&conn);
    row = mysql_fetch_row(result);

    sprintf(query, "INSERT INTO deleteuser (id,pw,name,usertype) VALUES ('%s', '%s','%s','%s')",row[0],row[1],row[2],row[3]);
    mysql_query(&conn, query); 
  
}

