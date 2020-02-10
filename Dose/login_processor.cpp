#include "login_processor.h"
#include <QDebug>
#include <QFile>
#include <QRegExp>

Lis::Login_processor::Login_processor(Controller *ct):Processor(ct){
    connection();
}

Lis::Login_processor::~Login_processor(){

}

void Lis::Login_processor::connection(){
    QObject::connect(this,SIGNAL(LoginSuccessfull()),this->_controller,SLOT(LoginCompleted()));
}

void Lis::Login_processor::loginCheck(QString username,QString password) {
    qDebug()<<username;
    qDebug()<<password;
    Login_failure_reason failReason;
    QFile loginfile ("./Login/login.txt");
    if (!loginfile.open(QIODevice::ReadOnly | QIODevice::Text))
        failReason= Passport_file_problem;
    qDebug()<<"file opened";
    QTextStream in(&loginfile);
    char match =0;
    while (!in.atEnd()&& match ==0 ) {
        QString line = in.readLine();
        QRegExp name("^name:"+username+".*$");
        if (name.exactMatch(line)){
            QRegExp pass(".*password:"+password+"$");
            if (pass.exactMatch(line)){
                _controller->username =username;
                emit LoginSuccessfull();
                return;
                qDebug()<<"hello, "+username;
            }else{
                failReason = Password_not_correct;
                qDebug()<<"Not correct password";
            }
            match =1;
        }
    }
    if(match ==0){
        failReason= No_such_user;
        qDebug()<<"No such user";
    }
    emit LoginFailed(failReason);
}



