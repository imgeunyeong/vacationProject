#include "header/showmenu.h"
#include "header/nomaluser.h"
#include <iostream>

void showmenu::nomaluser_show_main()
{
    int num = 0;
    while(1)
    {
        system("clear");
        std::cout<<"1. 회원가입"<<"  2. 로그인"<<"  3. ID찾기"<<"  4. PW찾기"<<"  5. 종료"<<std::endl;
        std::cin>>select;
        switch (select)
        {
            case 1: 
                user.signup();
                break;
            case 2:
                num = user.login();
                if(num==1)
                {    
                    nomaluser_show_select();
                    num = 0;
                }
                break;
            case 3:
                user.find_id();
                break;
            case 4:
                user.find_pw();
                break;
            case 5:
                return;
                break;
            default:
                break;
        }
    }
}

void showmenu::nomaluser_show_select()
{
    while(1)
    {
        system("clear");
        std::cout<<"1. 관광지 조회"<<"  2. 비밀번호 변경"<<"  3. 회원 탈퇴"<<std::endl;
        std::cin>>select;
        switch (select)
        {
        case 1:
            tour.show_tourist();
            break;
        case 2:
            user.change_pw();
            break;
        case 3:
            user.delete_information();
            return;
            break;
        default:
            break;
        }
    }
}

void showmenu::server_show_menu()
{
    while(1)
    {
        system("clear");
        std::cout<<"1. 회원 관리"<<"  2. 관광지 관리"<<"  3. 숙박 관리"<<"  4. 가이드 관리"<<"  5. 종료"<<std::endl;
        std::cin>>select;
        switch (select)
        {
        case 1:
            server_show_manage_menu();
            break;
        case 2:
            server_show_tourist_menu();
            break;
        case 3:
            server_show_stay_menu();
            break;
        case 4:
            server_show_guide_menu();
            break;
        case 5:
            return;
            break;
        default:
            break;
        }
    }
}

void showmenu::server_show_manage_menu()
{
    while (1)
    {
        system("clear");
        std::cout<<"1. 회원정보 조회"<<"  2. 회원등급 변경"<<"  3. 회원 삭제"<<"  4. 탈퇴/삭제 회원 목록"<<"  5. 나가기"<<std::endl;
        std::cin>>select;
        switch (select)
        {
        case 1:
            manageuser.show_user_list();
            break;
        case 2:
            manageuser.change_user_grade();
            break;
        case 3:
            manageuser.delete_user();
            break;
        case 4:
            manageuser.show_delete_user_list();
            break;
        case 5:
            return;
            break;
        default:
            break;
        }
    }
}

void showmenu::server_show_tourist_menu()
{
    while(1)
    {
        system("clear");
        std::cout<<"1. 관광지 목록"<<"  2. 관광지 추가"<<"  3. 관광지 수정"<<"  4. 관광지 삭제"<<" 5. 종료"<<std::endl;
        std::cin>>select;
        switch (select)
        {
        case 1:
            tour.show_tourist();
            break;
        case 2:
            tour.append_tourist();
            break;
        case 3:
            tour.change_tourist();
            break;
        case 4:
            tour.delete_tourist();
            break;
        case 5:
            return;
            break;
        default:
            break;
        }
    }
}

void showmenu::server_show_stay_menu()
{
    while(1)
    {
        system("clear");
        std::cout<<"1. 숙박업소 목록"<<"  2. 숙박업소 추가"<<"  3. 숙박업소 수정"<<"  4. 숙박업소 삭제"<<" 5. 종료"<<std::endl;
        std::cin>>select;
        switch (select)
        {
        case 1:
            stay.show_stay_list();
            break;
        case 2:
            stay.append_stay();
            break;
        case 3:
            stay.change_stay();
            break;
        case 4:
            stay.delete_stay();
            break;
        case 5:
            return;
            break;
        default:
            break;
        }
    }    
}

void showmenu::server_show_guide_menu()
{
    while(1)
    {
        system("clear");
        std::cout<<"1. 가이드 목록"<<"  2. 가이드 추가"<<"  3. 가이드 배정"<<"  4. 가이드 삭제"<<" 5. 종료"<<std::endl;
        std::cin>>select;
        switch (select)
        {
        case 1:
            guide.show_guide_list();
            break;
        case 2:
            guide.add_guide();
            break;
        case 3:
            guide.work_guide();
            break;
        case 4:
            guide.delete_guide();
            break;
        case 5:
            return;
            break;
        default:
            break;
        }
    }        
}