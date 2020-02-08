#include "login_processor.h"
#include <QDebug>
#include <QFile>
#include <QRegExp>
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
    char match =0;
    while (!in.atEnd()&& match ==0 ) {
        QString line = in.readLine();
        QRegExp name("^name:"+username+".*$");
        if (name.exactMatch(line)){
            QRegExp pass(".*password:"+password+"$");
            if (pass.exactMatch(line)){
                qDebug()<<"hello"+username;
            }else{
                qDebug()<<"Not correct password";
            }
            match =1;
        }
    }
    if(match ==0){
        qDebug()<<"No such user";
    }
}
//void Lis::Loginner::connection() {
//    QObject::connect(_controller->_widget,SIGNAL(login(QString,QString)),_controller->_processor,SLOT(loginCheck(QString,QString)));
//}
