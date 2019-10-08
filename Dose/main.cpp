#include "login_form.h"
#include <QApplication>
#include "controller.h"
#include "mainwindow.h"
#include "login_form.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lis::Controller cont;
    return a.exec();
}
