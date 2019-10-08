#include "loginner.h"
#include "login_form.h"
#include "mainwindow.h"

Lis::Loginner::Loginner(Login_form *p):Processor()
{
   _parent = p;
}

Lis::Loginner::~Loginner()
{

}

void Lis::Loginner::loginCheck(QString username,QString password) {
   _view_control = new MainWindow ();
   _view_control->show();
   this->~Loginner();
}
