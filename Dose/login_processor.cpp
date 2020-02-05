#include "login_processor.h"
#include <QDebug>


Lis::Login_processor::Login_processor(Controller *ct):Processor(ct){

}

Lis::Login_processor::~Login_processor(){

}

void Lis::Login_processor::loginCheck(QString username,QString password) {
    qDebug()<<username;
    qDebug()<<password;
}
//void Lis::Loginner::connection() {
//    QObject::connect(_controller->_widget,SIGNAL(login(QString,QString)),_controller->_processor,SLOT(loginCheck(QString,QString)));
//}
