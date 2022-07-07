#include "header/usermanagement.h"
#include <unistd.h>

void user_management::show_user_list()
{
    sprintf(query, "SELECT * FROM usertable");
    mysql_query(&conn, query);
    sql_result = mysql_store_result(&conn);
    while (sql_row = mysql_fetch_row(sql_result))
    {
        std::cout << "이름: " << sql_row[2] << "  ID: " << sql_row[0] << "  PW: " << sql_row[1] << "  회원등급: " << sql_row[3] << std::endl;
    }
    sleep(2);
    mysql_free_result(sql_result);
}

void user_management::delete_user()
{
    show_user_list();
    std::cout << "삭제할 회원 ID 입력: ";
    std::cin >> user_id;
    sprintf(query, "SELECT * FROM usertable where id ='%s'", user_id.c_str());
    if (mysql_query(&conn, query) != 0)
    {
        std::cout << "query error" << std::endl;
    }
    else
    {
        sql_result = mysql_store_result(&conn);
        sql_row = mysql_fetch_row(sql_result);
        sprintf(query, "INSERT INTO deleteuser(id, pw, name, usertype) VALUES('%s', '%s', '%s', '%s')", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
        if (mysql_query(&conn, query) != 0)
        {
            fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
        }
        else
        {
            sprintf(query, "delete from usertable where id= '%s'", user_id.c_str());
            if (mysql_query(&conn, query) != 0)
            {
                fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
            }
            else
            {
                std::cout << "삭제 완료" << std::endl;
                sleep(2);
            }
        }
    }
    mysql_free_result(sql_result);
}

void user_management::change_user_grade()
{
    int select;
    show_user_list();
    std::cout << "변경할 유저 ID 입력: ";
    std::cin >> user_id;
    std::cout << "변경할 등급을 선택하세요" << std::endl;
    std::cout << " 1.VIP 2.준회원: ";
    std::cin >> select;
    if (select == 1)
    {
        sprintf(query, "update usertable set usertype = 'v' where id ='%s'", user_id.c_str());
        if (mysql_query(&conn, query) != 0)
        {
            std::cout << "query error" << std::endl;
        }
        else
        {
            std::cout << "변경 완료" << std::endl;
            sleep(2);
        }
    }
    else if (select == 2)
    {
        sprintf(query, "update usertable set usertype = 'n' where id ='%s'", user_id.c_str());
        if (mysql_query(&conn, query) != 0)
        {
            std::cout << "query error" << std::endl;
        }
        else
        {
            std::cout << "변경 완료" << std::endl;
            sleep(2);
        }
    }
}

void user_management::show_delete_user_list()
{
    sprintf(query, "SELECT * FROM deleteuser");
    mysql_query(&conn, query);
    sql_result = mysql_store_result(&conn);
    while (sql_row = mysql_fetch_row(sql_result))
    {
        std::cout << "이름: " << sql_row[2] << "ID: " << sql_row[0] << "PW: " << sql_row[1] << "회원등급: " << sql_row[3] << std::endl;
    }
    sleep(2);
    mysql_free_result(sql_result);    
}