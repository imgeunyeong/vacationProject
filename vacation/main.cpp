#include <iostream>
#include "database.h"
#include "search.h" 
#include "Reserv.h" 
#include "Edit.h" 
#include "Regit.h" 
#include "Login.h" 
#include "FirstPage.h" 
#include "DropUser.h"
#include "ChangeInfo.h"

using namespace std;

int main(void)
{   
    FirstPage obj;
    obj.showMenu();
    while(1)
    {
        int input;
        cout<<"\n";
        cout<<"=== 메뉴 ==="<<endl;
        cout<<"1.예약하기 2.예약수정 3.예약조회 4.회원정보수정 5.회원탈퇴 0.종료"<<endl;
        cin>>input;
        switch (input)
        {
        case 0:
            return 0;

        case 1:
        {
            Reserv reservObj;
            reservObj.startReserv();
            continue;;
        }
        case 2:
        {
            Edit editObj;
            editObj.changeReserv();
            continue;;
        }
        case 3:
        {   Edit editObj2;
            editObj2.checkReserv();
            continue;
        }
         case 4:
        {  ChangeInfo changeObj;
            changeObj.showMenu();
            continue;
        }
         case 5:
        {  DropUser dropObj;
           dropObj.byebye();
            return 0;
        }
        default:
            cout<<"선택지를 다시 골라주세요"<<endl;
            continue;
        }
    }
}
