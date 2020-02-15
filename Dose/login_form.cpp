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
    QObject::connect(this,SIGNAL(login(QString,QString)),this->_LoginProcessor,SLOT(loginCheck(QString,QString)));
    QObject::connect(this->_LoginProcessor,SIGNAL(loginFailed(Lis::Login_processor::Login_failure_reason)),this,SLOT(indicateFailReason(Lis::Login_processor::Login_failure_reason)));
}

void Login_form::on_buttonBox_Login_accepted()
{
    emit this->login(ui->lineEdit_UserName->text(),ui->lineEdit_Password->text());
}

void Login_form::indicateFailReason(Login_processor::Login_failure_reason r){
    ui->lineEdit_Password->setText(failure[r]);
}
