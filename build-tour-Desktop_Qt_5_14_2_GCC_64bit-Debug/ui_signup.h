/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QLabel *ID_label;
    QLabel *PW_label;
    QLineEdit *PW_input;
    QLabel *Name_label;
    QLineEdit *Name_input;
    QPushButton *ID_check_btn;
    QPushButton *Out_btn;
    QPushButton *Signup_btn;
    QLineEdit *ID_input;

    void setupUi(QDialog *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName(QString::fromUtf8("signup"));
        signup->resize(400, 300);
        ID_label = new QLabel(signup);
        ID_label->setObjectName(QString::fromUtf8("ID_label"));
        ID_label->setGeometry(QRect(51, 61, 16, 17));
        PW_label = new QLabel(signup);
        PW_label->setObjectName(QString::fromUtf8("PW_label"));
        PW_label->setGeometry(QRect(51, 115, 24, 17));
        PW_input = new QLineEdit(signup);
        PW_input->setObjectName(QString::fromUtf8("PW_input"));
        PW_input->setGeometry(QRect(51, 138, 142, 25));
        PW_input->setEchoMode(QLineEdit::Password);
        Name_label = new QLabel(signup);
        Name_label->setObjectName(QString::fromUtf8("Name_label"));
        Name_label->setGeometry(QRect(51, 169, 41, 17));
        Name_input = new QLineEdit(signup);
        Name_input->setObjectName(QString::fromUtf8("Name_input"));
        Name_input->setGeometry(QRect(51, 192, 142, 25));
        ID_check_btn = new QPushButton(signup);
        ID_check_btn->setObjectName(QString::fromUtf8("ID_check_btn"));
        ID_check_btn->setGeometry(QRect(200, 81, 80, 31));
        Out_btn = new QPushButton(signup);
        Out_btn->setObjectName(QString::fromUtf8("Out_btn"));
        Out_btn->setGeometry(QRect(300, 250, 89, 25));
        Signup_btn = new QPushButton(signup);
        Signup_btn->setObjectName(QString::fromUtf8("Signup_btn"));
        Signup_btn->setGeometry(QRect(190, 250, 89, 25));
        ID_input = new QLineEdit(signup);
        ID_input->setObjectName(QString::fromUtf8("ID_input"));
        ID_input->setGeometry(QRect(52, 84, 142, 25));

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QDialog *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Dialog", nullptr));
        ID_label->setText(QCoreApplication::translate("signup", "ID", nullptr));
        PW_label->setText(QCoreApplication::translate("signup", "PW", nullptr));
        PW_input->setText(QString());
        Name_label->setText(QCoreApplication::translate("signup", "Name", nullptr));
        Name_input->setText(QString());
        ID_check_btn->setText(QCoreApplication::translate("signup", "\354\244\221\353\263\265\355\231\225\354\235\270", nullptr));
        Out_btn->setText(QCoreApplication::translate("signup", "\353\202\230\352\260\200\352\270\260", nullptr));
        Signup_btn->setText(QCoreApplication::translate("signup", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        ID_input->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
