
#include <iostream>
#include "database.h"
#include "Login.h"
using namespace std;
string Login::id;

    void Login::tryLogin()
    {
        while (1)
        {
            inputLogin();
            sprintf(query, "SELECT id,pw FROM usertable where id='%s'and pw='%s'",userid.c_str(), pw.c_str());
            if (mysql_query(&conn, query) != 0)
            {
                fprintf(stderr, "Failed to connect to databases: Error: %s\n",
                        mysql_error(&conn));
            }
            result = mysql_store_result(&conn);
            if ((row = mysql_fetch_row(result)) == NULL)
                cout << "로그인 실패" << endl;
            else
            {
                cout << "로그인 성공" << endl;
                id = userid;                
                return;
            }
        }
    }

    void Login::inputLogin()
    {
        cout << "=== 로그인 ===" << endl;
        cout << "id 입력해주세요: " << endl;
        cin >> userid;
        cout << "pw 입력해주세요: " << endl;
        cin >> pw;
    }
