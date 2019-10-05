#include "login_form.h"
#include "ui_login_form.h"
#include "loginner.h"

Login_form::Login_form(QWidget *parent, MainWindow** mainw)
    : QDialog(parent)
    , ui(new Ui::Login_form)
{
    _mw=mainw;
    ui->setupUi(this);
    _loginner = new Lis::Loginner(this);
    QObject::connect(this,SIGNAL(login(QString,QString)),_loginner,SLOT(loginCheck(QString,QString)));
}

Login_form::~Login_form()
{
    delete _mw;
    delete ui;
    delete _loginner;
}


void Login_form::on_buttonBox_Login_accepted()
{       
    emit this->login(ui->lineEdit_UserName->text(),ui->lineEdit_Password->text());
}
