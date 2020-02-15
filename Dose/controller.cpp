#include "controller.h"
#include "login_form.h"
#include "mainwindow.h"
#include <QObject>
#include <QDebug>

Lis::Controller::Controller():QObject()
{
    _settings = new Settings();
    _settings->read();
    _logger = new Logger();
    _widget = new Login_form(this);
    _widget->show();

}

Lis::Controller::~Controller(){

}

void Lis::Controller::loginCompleted(QString username){
    _username = username;
    _logger->write_login_history(username);
    delete _widget;
    qDebug()<< "close Login form";
    _widget = new MainWindow(this);
    qDebug()<< "MW created";
    _widget->show();

}

