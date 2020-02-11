#include "controller.h"
#include "login_form.h"
#include "mainwindow.h"
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
    _widget = new MainWindow(this);
    qDebug()<< "MW created";
    _widget->show();

}

