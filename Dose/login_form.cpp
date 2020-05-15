#include "login_form.h"
#include "ui_login_form.h"
#include "login_processor.h"
#include "QMouseEvent"
#include "QDebug"

Login_form::Login_form(Controller *ct, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login_form)
{
    ui->setupUi(this);
    _EvFilter =new EventFilter_Login_Form(ui);
    ui->lineEdit_UserName->installEventFilter(_EvFilter);
    ui->lineEdit_Password->installEventFilter(_EvFilter);
    _LoginProcessor = new Login_processor(ct,this);
    connection();
}

Login_form::~Login_form()
{
    delete ui;
    delete _LoginProcessor;
    delete _EvFilter;
}

void Login_form::connection(){
    QObject::connect(this,SIGNAL(login(QString,QString)),this->_LoginProcessor,SLOT(verify_login(QString,QString)));
}

void Login_form::on_buttonBox_Login_accepted()
{
   if(ui->lineEdit_UserName->text() == NULL){
      ui->lineEdit_UserName->setText("Enter your Login, please");
   }else if(ui->lineEdit_Password->text()==NULL){
      ui->lineEdit_Password->setText("Enter your password, please");
   }else{
        emit this->login(ui->lineEdit_UserName->text(),ui->lineEdit_Password->text());
   }
}


void Login_form::indicate_fail_reason(Verification_result r){
    qDebug()<<"indicate";
    ui->lineEdit_Password->setText(failure[r]);
    qDebug()<<"indicate";
}


