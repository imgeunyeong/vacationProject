#include "signup.h"
#include "ui_signup.h"
#include "database.h"
#include <QMessageBox>

signup::signup(Database db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup),
    db(db)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_ID_check_btn_clicked()
{
    query_string="SELECT ID FROM user WHERE ID='"+ui->ID_input->text().toStdString()+"'";
    query.exec(QString::fromStdString(query_string));
    if(query.size()==0)
    {
        QMessageBox::information(this,"ok","ok");
        check=true;
    }
    else
    {
        QMessageBox::information(this,"no","no");
    }
}

void signup::on_Signup_btn_clicked()
{
    if(check==false)
    {
        QMessageBox::warning(this,"fail","ID 중복을 확인하세요");
    }
    else
    {
        query.prepare("INSERT INTO usertable (ID,PW,Name)" "VALUES (?,?,?)");
        query.addBindValue(ui->ID_input->text());
        query.addBindValue(ui->PW_input->text());
        query.addBindValue(ui->Name_input->text());
        query.exec();
        QMessageBox::information(this,"축하합니다","회원가입 완료");
        this->close();
        }
    }


void signup::on_Out_btn_clicked()
{
     this->close();
}
