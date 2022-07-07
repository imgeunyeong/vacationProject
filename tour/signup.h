#ifndef SIGNUP_H
#define SIGNUP_H
#include <database.h>
#include <cstring>
#include <QDialog>
#include <QtWidgets>

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(Database db, QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_ID_check_btn_clicked();

    void on_Signup_btn_clicked();

    void on_Out_btn_clicked();

private:
    Ui::signup *ui;
    Database db;
    QSqlQuery query;
    std::string query_string;
    bool check;
};

#endif // SIGNUP_H
