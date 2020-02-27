#include "controller.h"
#include "login_form.h"
#include "mainwindow.h"
#include <QObject>
#include <QDebug>

Lis::Controller::Controller():QObject()
{

    _settings = Settings::getInstance();
    if(_settings->_initResult){
        _logger = new Logger();
        _widget = new Login_form(this);
        _widget->show();
    }else{
        delete _settings;
        this->AppState = false;
    }
}

Lis::Controller::~Controller(){

}

void Lis::Controller::Autorisation_Passed(QString username){
    _username = username;
    _logger->write_login_history(username);
    delete _widget;
    qDebug()<< "close Login form";
    _widget = new MainWindow(this);
    qDebug()<< "MW created";
    _widget->show();

}

