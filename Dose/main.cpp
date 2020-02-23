#include <QApplication>
#include "controller.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lis::Controller cont;
    if(cont.AppState){
        return a.exec();
    }else{
        a.quit();
    }
}
