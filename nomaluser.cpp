# include "header/nomaluser.h"

void nomaluser::signup()
{
    std::cout<<"ID 입력: ";
    std::cin>>id;
    std::cout<<"PW 입력: ";
    std::cin>>pw;
    std::cout<<"이름 입력: ";
    std::cin>>name;
    sprintf(query, "INSERT INTO usertable(id, pw, name, usertype) VALUES('%s', '%s', '%s', 'n')", id.c_str(), pw.c_str(), name.c_str());
    if(mysql_query(&conn, query)!=0)
    {
        fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
    }
    else
    {
        std::cout<<"회원가입 완료"<<std::endl;
        sleep(2);
    }
}

int nomaluser::login()
{
    std::cout<<"ID 입력: ";
    std::cin>>id;
    std::cout<<"PW 입력: ";
    std::cin>>pw;
    sprintf(query, "SELECT pw FROM usertable where id ='%s'", id.c_str());
    if(mysql_query(&conn, query)!=0)
    {
        std::cout<<"query error"<<std::endl;
    }
    else
    {
        sql_result = mysql_store_result(&conn);
        sql_row = mysql_fetch_row(sql_result);
        if(strcmp(pw.c_str(), sql_row[0])==0)
        {
            std::cout<<"로그인 성공"<<std::endl;
            sleep(2);
            return 1;
        }
        else
        {
            std::cout<<"id/pw 오류"<<std::endl;
        }
    }
    mysql_free_result(sql_result);
}

void nomaluser::find_id()
{
    std::cout<<"이름 입력: ";
    std::cin>>name;
    sprintf(query, "SELECT id FROM usertable where name ='%s'", name.c_str());
    if(mysql_query(&conn, query)!=0)
    {
        std::cout<<"query error"<<std::endl;
    }
    else
    {
        sql_result = mysql_store_result(&conn);
        sql_row = mysql_fetch_row(sql_result);
        std::cout<<"ID: "<< sql_row[0]<<std::endl;
        sleep(2);
    }
    mysql_free_result(sql_result);
}
void nomaluser::find_pw()
{
    std::cout<<"ID 입력: ";
    std::cin>>id;
    sprintf(query, "SELECT pw FROM usertable where id ='%s'", id.c_str());
    if(mysql_query(&conn, query)!=0)
    {
        std::cout<<"query error"<<std::endl;
    }
    else
    {
        sql_result = mysql_store_result(&conn);
        sql_row = mysql_fetch_row(sql_result);
        std::cout<<"PW: "<< sql_row[0]<<std::endl;
        sleep(2);
    }
    mysql_free_result(sql_result);
}

void nomaluser::change_pw()
{
    std::cout<<"ID입력: ";
    std::cin>>id;
    std::cout<<"변경할 비밀번호 입력: ";
    std::cin>>pw;
    sprintf(query, "update usertable set pw = '%s' where id ='%s'", pw.c_str(), id.c_str());
    if(mysql_query(&conn, query)!=0)
    {
        std::cout<<"query error"<<std::endl;
    }
    else
    {
        std::cout<<"변경 완료"<<std::endl;
        sleep(2);
    }

}

void nomaluser::delete_information()
{
    char select;
    std::cout << "삭제할 ID 입력: ";
    std::cin >> id;
    sprintf(query, "SELECT * FROM usertable where id ='%s'", id.c_str());
    if (mysql_query(&conn, query) != 0)
    {
        std::cout << "query error" << std::endl;
    }
    else
    {
        sql_result = mysql_store_result(&conn);
        sql_row = mysql_fetch_row(sql_result);
        std::cout<<"본인 정보가 맞나요? (y/n)"<<std::endl;
        std::cout << "이름: " << sql_row[2] << "  ID: " << sql_row[0] << "  PW: " << sql_row[1] << "  회원등급: " << sql_row[3] << std::endl;
        std::cin>>select;
        if(select=='y' || select=='Y')
        {
            sprintf(query, "INSERT INTO deleteuser(id, pw, name, usertype) VALUES('%s', '%s', '%s', '%s')", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
            if (mysql_query(&conn, query) != 0)
            {
                fprintf(stderr, "database connect error : %s\n", mysql_error(&conn));
            }
            else
            {
                sprintf(query, "delete from usertable where id= '%s'", id.c_str());
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
        else if(select == 'n' || select=='N')
        {
            return;
        }
    }
    mysql_free_result(sql_result);    
}
