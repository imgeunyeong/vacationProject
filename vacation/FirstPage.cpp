#include <iostream>
#include "database.h"
#include "FirstPage.h"
#include "Login.h" 
#include "Regit.h"
using namespace std;

void FirstPage::showMenu()
{  
    while(1)
    {
        cout<<"=== 메뉴 ==="<<endl;
        cout<<"1. 회원가입"<<endl;
        cout<<"2. 로그인"<<endl;
        cout<<"0. 종료"<<endl;
        cin>>input;
        switch (input)
        {
        case 0:
            exit(1);

        case 1:
        {
            Regit regobj;
            regobj.signUp();
            continue;
        }
        case 2:
        {
            Login logobj;
            logobj.tryLogin();
            return;
        }   
        default:
            cout<<"선택지를 제대로 입력해주세요"<<endl;
            break;
        }
    }
}
