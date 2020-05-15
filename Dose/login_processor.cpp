#include "login_processor.h"


Lis::Login_processor::Login_processor(Controller *ct, QObject *parent):Processor(ct,parent){
    connection();
}

Lis::Login_processor::~Login_processor(){

}

void Lis::Login_processor::connection()  {
    QObject::connect(this,SIGNAL(verification_passed(QString)),this->_controller,SLOT(autorisation_pass(QString)));
    QObject::connect(this,SIGNAL(verification_failed(Verification_result)),this->parent(),SLOT(indicate_fail_reason(Verification_result)));
}

void Lis::Login_processor::verify_login(QString username,QString password) {
    Verification_result vres =verify(username,password);
    if (vres== Verification_result::Verification_Passed){
        emit verification_passed(username);
    }else{
        emit verification_failed(vres);
    }

}



