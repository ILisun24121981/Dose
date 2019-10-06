#include "loginner.h"
#include "login_form.h"
#include "mainwindow.h"



Lis::Loginner::Loginner(QWidget *v):Processor()
{
   _view = v;
}

Lis::Loginner::~Loginner()
{

}

void Lis::Loginner::loginCheck(QString username,QString password) {
   delete _view;
   _view = new MainWindow ();
}
