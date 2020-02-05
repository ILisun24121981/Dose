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
}

void Login_form::connection(){
    //QObject::connect(this->ui->buttonBox_Login,SIGNAL(accepted()),this,SLOT(on_buttonBox_Login_accepted()));
    QObject::connect(this,SIGNAL(login(QString,QString)),this->_LoginProcessor,SLOT(loginCheck(QString,QString)));
}

void Login_form::on_buttonBox_Login_accepted()
{
    emit this->login(ui->lineEdit_UserName->text(),ui->lineEdit_Password->text());
}
