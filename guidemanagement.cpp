#include "header/guidemanagement.h"

void guide_management::show_guide_list()
{
    sprintf(query, "SELECT * FROM guide");
    mysql_query(&conn, query);
    sql_result = mysql_store_result(&conn);
    while (sql_row = mysql_fetch_row(sql_result))
    {
        std::cout << "이름: " << sql_row[0] << "  근무가능: " << sql_row[4] << std::endl;
    }
    sleep(2);
    mysql_free_result(sql_result);
}

void guide_management::add_guide()
{
    std::cout << "가이드 이름 입력: ";
    std::cin >> guide_name;
    sprintf(query, "INSERT INTO guide(name, course, date, user_id, work) VALUES('%s', '', '', '', 'o')", guide_name.c_str());
    if (mysql_query(&conn, query) != 0)
    {
        fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
    }
    else
    {
        std::cout << "추가 완료" << std::endl;
        sleep(2);
    }
}

void guide_management::work_guide()
{
    std::string user_id;
    std::cout << "가이드 신청 명단" << std::endl;
    sprintf(query, "SELECT id, coursecontent, date FROM reservation where guide = 'y' and guide_assign = 'x'");
    mysql_query(&conn, query);
    sql_result = mysql_store_result(&conn);
    while (sql_row = mysql_fetch_row(sql_result))
    {
        std::cout << "ID: " << sql_row[0] << "  코스: " << sql_row[1] << "  날짜: " << sql_row[2] << std::endl;
    }
    std::cout << std::endl<< std::endl;
    std::cout << "가이드 명단" << std::endl;
    show_guide_list();
    std::cout << "선택할 가이드 이름 입력: ";
    std::cin >> guide_name;
    std::cout << "배정할 회원 아이디 입력: ";
    std::cin >> user_id;
    sprintf(query, "SELECT id, coursecontent, date FROM reservation where id ='%s'", user_id.c_str()); 
    if (mysql_query(&conn, query) != 0)
    {
        std::cout << "query error" << std::endl;
    }
    else
    {
        sql_result = mysql_store_result(&conn);
        sql_row = mysql_fetch_row(sql_result);   
        sprintf(query, "update guide set course = '%s', date='%s', user_id='%s', work='n' where name ='%s'", sql_row[1], sql_row[2], sql_row[0], guide_name.c_str());
        if (mysql_query(&conn, query) != 0)
        {
            fprintf(stderr, "Failed to connect to databases: Error: %s\n",mysql_error(&conn));
        }
        else
        {
            sprintf(query, "update reservation set guide_assign='o' where id ='%s'", user_id.c_str());
            if (mysql_query(&conn, query) != 0)
            {
                fprintf(stderr, "Failed to connect to databases: Error: %s\n",mysql_error(&conn));
            }
            else
            {
                std::cout << "배정 완료" << std::endl;
                sleep(2);
            }
        }
    }
    mysql_free_result(sql_result);
}

void guide_management::delete_guide()
{
    show_guide_list();
    std::cout<<"가이드 이름 입력: ";
    std::cin>>guide_name;
    sprintf(query, "delete from guide where name = '%s'", guide_name.c_str());
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