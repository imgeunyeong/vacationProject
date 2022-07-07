#include "header/staymanagement.h"
#include <unistd.h>

void stay_management::show_stay_list()
{
    sprintf(query, "SELECT * FROM stay");
    mysql_query(&conn, query);
    sql_result = mysql_store_result(&conn);  
    while(sql_row = mysql_fetch_row(sql_result))
    {
        std::cout<<sql_row[0]<<": "<< sql_row[1]<<std::endl;
    }
    sleep(2);
    mysql_free_result(sql_result);
}

void stay_management::delete_stay()
{
    show_stay_list();
    std::cout<<"삭제할 숙박 이름 입력: ";
    std::cin>>stay_name;
    sprintf(query, "delete from stay where stayname = '%s'", stay_name.c_str());
    if(mysql_query(&conn, query)!=0)
    {
        fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
    }
    else
    {
        std::cout<<"삭제 완료"<<std::endl;
        sleep(2);
    }
}

void stay_management::append_stay()
{
    std::cout<<"추가할 숙박 입력: ";
    std::cin>>stay_name;
    std::cout<<"주소 입력: ";
    std::cin>>stay_address;
    sprintf(query, "INSERT INTO stay(stayname, stayaddress) VALUES('%s','%s')", stay_name.c_str(), stay_address.c_str());
    if(mysql_query(&conn, query)!=0)
    {  
        fprintf(stderr, "Failed to connect to databases: Error: %s\n",
        mysql_error(&conn));
    }
    else
    {
        std::cout<<"추가 성공"<<std::endl;
        sleep(2);
    }
}

void stay_management::change_stay()
{
    int select;
    std::string change_name;
    std::string change_address;
    show_stay_list();
    std::cout<<"수정할 숙박 이름 입력: ";
    std::cin>>stay_name;
    std::cout<<"1. 이름변경 2. 주소변경 :  ";
    std::cin>>select;
    if(select==1)
    {
        std::cout<<"변경할 이름 입력: ";
        std::cin>>change_name;
        sprintf(query, "update stay set stayname = '%s' where stayname ='%s'", change_name.c_str(), stay_name.c_str());
        if(mysql_query(&conn, query)!=0)
        {  
            fprintf(stderr, "Failed to connect to databases: Error: %s\n",
            mysql_error(&conn));
        }
        else
        {
            std::cout<<"수정 완료"<<std::endl;
            sleep(2);
        }
    }
    else if(select==2)
    {
        std::cout<<"변경할 주소 입력: ";
        std::cin>>change_address;
        sprintf(query, "update stay set stayaddress = '%s' where stayname ='%s'", change_address.c_str(), stay_name.c_str());
        if(mysql_query(&conn, query)!=0)
        {  
            fprintf(stderr, "Failed to connect to databases: Error: %s\n",
            mysql_error(&conn));
        }
        else
        {
            std::cout<<"수정 완료"<<std::endl;
            sleep(2);
        }
    }
}