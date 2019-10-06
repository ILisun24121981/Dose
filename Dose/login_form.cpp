#include "login_form.h"
#include "ui_login_form.h"
#include "loginner.h"

Login_form::Login_form(Controller *ct, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login_form)
{  
    ui->setupUi(this);
    ct->_pr = new Lis::Loginner(ct->_view);
    QObject::connect(this,SIGNAL(login(QString,QString)),ct->_pr,SLOT(loginCheck(QString,QString)));
}

Login_form::~Login_form()
{
    delete ui;
}


void Login_form::on_buttonBox_Login_accepted()
{       
    emit this->login(ui->lineEdit_UserName->text(),ui->lineEdit_Password->text());
}
