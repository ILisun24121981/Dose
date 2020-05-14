#include "login_processor.h"


Lis::Login_processor::Login_processor(Controller *ct):Processor(ct){
    _strategy = new Txt_login_processor();
    connection();
}

Lis::Login_processor::~Login_processor(){

}

void Lis::Login_processor::connection(){
    QObject::connect(this,SIGNAL(verification_passed(QString)),this->_controller,SLOT(autorisation_pass(QString)));
}

void Lis::Login_processor::verify_login(QString username,QString password) {
    Verification_result vres;
    if ((vres =_strategy->verify(username,password))== Verification_result::Verification_Passed){
        emit verification_passed(username);
    }else{
        emit verification_failed(vres);
    }

}



