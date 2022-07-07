#include <iostream>
#include <unistd.h>
#include "database.h"
#include "Regit.h"
using namespace std;

    void Regit::signUp()
    {
        while (1)
        {
            cout << "id: " << endl;
            cin >> id;

            sprintf(query, "SELECT id FROM usertable where id='%s'", id.c_str());
            mysql_query(&conn, query);

            result = mysql_store_result(&conn);
            if ((row = mysql_fetch_row(result)) == NULL) //찾는결과 없음
            {
                inputInfo();
                sprintf(query, "INSERT INTO usertable VALUES('%s','%s','%s','%s')", id.c_str(), pw.c_str(),name.c_str(),"v");
                mysql_query(&conn, query);
                break;
            }
            else
            {
                cout << "중복된 아이디입니다" << endl;
                continue;
            }
        }
    }
    void Regit::inputInfo()
    {
        cout << "사용 가능한 아이디입니다" << endl;
        cout << "pw: " << endl;
        cin >> pw;
        cout << "name: "<<endl;
        cin >> name;
        cout << "회원 가입 완료!" << endl;
        sleep(1);
        system("clear");
    }

