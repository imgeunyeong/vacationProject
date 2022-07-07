#include "signup.h"
#include "database.h"
#include "QApplication"

int main(int argc, char *argv[])
{
    Database db;
    db.database_init();
    QApplication a(argc, argv);
    signup sign(db);
    sign.show();
    return a.exec();
}
