#include "header/touristmanagement.h"
#include <unistd.h>

void tourist_management::show_tourist()
{
    system("clear");
    sprintf(query, "SELECT * FROM spot");
    mysql_query(&conn, query);
    sql_result = mysql_store_result(&conn);  
    while(sql_row = mysql_fetch_row(sql_result))
    {
        std::cout<<sql_row[0]<<": "<< sql_row[1]<<std::endl;
    }
    sleep(2);
    mysql_free_result(sql_result);
}

void tourist_management::delete_tourist()
{
    show_tourist();
    std::cout<<"삭제할 관광지 번호 입력: ";
    std::cin>>tourist_num;
    sprintf(query, "delete from spot where coursenum = '%d'", tourist_num);
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

void tourist_management::append_tourist()
{
    int append_num;
    sprintf(query, "SELECT coursenum FROM spot");
    mysql_query(&conn, query);
    sql_result = mysql_store_result(&conn);  
    while(sql_row = mysql_fetch_row(sql_result))
    {
        append_num=atoi(sql_row[0]);
    } 
    append_num++;
    std::cout<<"추가할 관광지 입력: ";
    std::cin>>tourist_name;
    sprintf(query, "INSERT INTO spot(coursenum, stand) VALUES('%d','%s')", append_num, tourist_name.c_str());
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

void tourist_management::change_tourist()
{
    show_tourist();
    std::cout<<"수정할 관광지 번호 입력: ";
    std::cin>>tourist_num;
    std::cout<<"수정할 내용 입력: ";
    std::cin>>tourist_name;
    sprintf(query, "update spot set stand = '%s' where coursenum ='%d'", tourist_name.c_str(), tourist_num);
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