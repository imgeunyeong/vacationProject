#include <iostream>
#include "database.h"
#include "Login.h"
#include "ChangeInfo.h"
using namespace std;


void ChangeInfo::showMenu()
{
    cout<<"1.회원 이름 변경 2.비밀번호 변경"<<endl;
    cin>>select;
    switch (select)
    {
    case 1:
        changeName();
        break;
    case 2:
        changePW();
        break;
    default:
        cout<<"올바른 선택지를 입력해주세요"<<endl;
        break;
    }
}

void ChangeInfo::changeName()
{   
    cout<<"변경할 이름을 입력해주세요"<<endl;
    cin>>input;
    sprintf(query, "UPDATE usertable SET name='%s'WHERE id='%s'",input.c_str(),Login::id.c_str());
            mysql_query(&conn, query);
            result = mysql_store_result(&conn);
            cout<<"name: "<<input<<" "<<"로 변경 완료"<<endl;
} 
void ChangeInfo::changePW()
{
    cout<<"변경할 비밀번호를 입력해주세요"<<endl;
    cin>>input;
    sprintf(query, "UPDATE usertable SET pw='%s'WHERE id='%s'",input.c_str(),Login::id.c_str());
            mysql_query(&conn, query);
            result = mysql_store_result(&conn);
            cout<<"비밀번호 변경 완료"<<endl;
}

