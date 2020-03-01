#include "login_form.h"
#include "ui_login_form.h"
#include "login_processor.h"

Login_form::Login_form(Controller *ct, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login_form)
{
    ui->setupUi(this);
    _LoginProcessor = new Login_processor(ct);
    connection();
}

Login_form::~Login_form()
{
    delete ui;
    delete _LoginProcessor;
}

void Login_form::connection(){
    QObject::connect(this,SIGNAL(login(QString,QString)),this->_LoginProcessor,SLOT(Verify_Login(QString,QString)));
    QObject::connect(this->_LoginProcessor,SIGNAL(Verification_Failed(Lis::Login_processor::Verification_result)),this,SLOT(indicateFailReason(Lis::Login_processor::Verification_result)));
}

void Login_form::on_buttonBox_Login_accepted()
{
   if(ui->lineEdit_UserName->text() == NULL){
      ui->lineEdit_UserName->setText("What a FACK?");
   }else{
        emit this->login(ui->lineEdit_UserName->text(),ui->lineEdit_Password->text());
   }
}


void Login_form::indicateFailReason(Lis::Login_processor::Verification_result r){
    ui->lineEdit_Password->setText(failure[r]);
}
