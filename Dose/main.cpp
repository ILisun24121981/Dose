#include "login_form.h"
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *m = nullptr;
    MainWindow **mw = &m;

    Login_form *w = new Login_form (nullptr,mw);
    w->show();

//    Login_form w;
//    w.show();
    return a.exec();
}
