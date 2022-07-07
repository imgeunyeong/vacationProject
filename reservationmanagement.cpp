#include "header/reservationmanagement.h"

void reservation_management::show_reservation_list()
{
    sprintf(query, "SELECT * FROM reservation");
    mysql_query(&conn, query);
    sql_result = mysql_store_result(&conn);  
    while(sql_row = mysql_fetch_row(sql_result))
    {
        std::cout<<"ID: "<< sql_row[0]<<"  코스: "<<sql_row[2]<<"  숙박: "<<sql_row[6]<<"  가이드: "<<sql_row[4]<<"  날짜: "<<sql_row[5]<<std::endl;
    }
    sleep(2);
    mysql_free_result(sql_result);
}

void reservation_management::show_delete_reservation_list()
{
    sprintf(query, "SELECT * FROM deletereservation");
    mysql_query(&conn, query);
    sql_result = mysql_store_result(&conn);
    while (sql_row = mysql_fetch_row(sql_result))
    {
        std::cout<<"ID: "<< sql_row[0]<<"  코스: "<<sql_row[2]<<"  숙박: "<<sql_row[6]<<"  가이드: "<<sql_row[4]<<"  날짜: "<<sql_row[5]<<std::endl;
    }
    sleep(2);
    mysql_free_result(sql_result);    
}
