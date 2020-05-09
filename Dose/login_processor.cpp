#include "login_processor.h"


Lis::Login_processor::Login_processor(Controller *ct):Processor(ct),Txt_login_processor(){
    connection();
}

Lis::Login_processor::~Login_processor(){

}

void Lis::Login_processor::connection(){
    QObject::connect(this,SIGNAL(verification_passed(QString)),this->_controller,SLOT(autorisation_passed(QString)));
}

void Lis::Login_processor::verify_login(QString username,QString password) {
    if ((this->_verResult = check_account(username,password))==Verification_result::Verification_Passed){
        emit verification_passed(username);
    }else{
        emit verification_failed(this->_verResult);//connected to Login_Form::indicate_fail_reason(Lis::Login_processor::Verification_result)
    }

}



