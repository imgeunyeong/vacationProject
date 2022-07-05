#include <iostream>
#include "database.h"
using namespace std;

int main(void)
{
    Database obj; 
    char query[1024]; 
    sprintf(query, "SELECT * FROM usertable"); 
    mysql_query(&obj.conn, query);  
    obj.result = mysql_store_result(&obj.conn); 
    while(obj.row = mysql_fetch_row(obj.result))
        cout<<obj.row[0]<<endl;
    return 0;
}