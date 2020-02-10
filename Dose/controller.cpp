#include "controller.h"
#include "login_form.h"
#include <QObject>
#include <QDebug>

Lis::Controller::Controller():QObject()
{
    _widget = new Login_form(this);
    _widget->show();

}

Lis::Controller::~Controller(){

}

void Lis::Controller::LoginCompleted(){
    delete _widget;
    qDebug()<< "close Login form";
}

