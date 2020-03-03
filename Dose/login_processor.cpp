#include "login_processor.h"


Lis::Login_processor::Login_processor(Controller *ct):Processor(ct),Txt_login_processor(){
    connection();
}

Lis::Login_processor::~Login_processor(){

}

void Lis::Login_processor::connection(){
    QObject::connect(this,SIGNAL(Verification_Passed(QString)),this->_controller,SLOT(Autorisation_Passed(QString)));
}

void Lis::Login_processor::verify_login(QString username,QString password) {
    if ((this->_result = check_account(username,password))==Verification_result::Verification_Passed){
        emit verification_passed(username);
    }else{
        emit verification_failed(this->_result);
    }

}



