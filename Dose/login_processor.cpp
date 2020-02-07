#include "login_processor.h"
#include <QDebug>
#include <QFile>

Lis::Login_processor::Login_processor(Controller *ct):Processor(ct){

}

Lis::Login_processor::~Login_processor(){

}

void Lis::Login_processor::loginCheck(QString username,QString password) {
    qDebug()<<username;
    qDebug()<<password;

    QFile loginfile ("./Login/login.txt");
    if (!loginfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    qDebug()<<"file opened";
    QTextStream in(&loginfile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug()<<line;
    }
}
//void Lis::Loginner::connection() {
//    QObject::connect(_controller->_widget,SIGNAL(login(QString,QString)),_controller->_processor,SLOT(loginCheck(QString,QString)));
//}
