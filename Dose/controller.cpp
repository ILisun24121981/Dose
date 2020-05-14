#include "controller.h"
#include "login_form.h"
#include "mainwindow.h"
#include <QObject>
#include <QDebug>

Lis::Controller::Controller():QObject()
{
    _settings = Settings::get_instance();
    if(_settings->_initResult){
        _logger = new Txt_logger();
        _widget = new Login_form(this);
        _widget->show();
    }else{
        delete _settings;
        this->AppState = false;
    }
}

Lis::Controller::~Controller(){

}

void Lis::Controller::autorisation_pass(QString username){//connected to
    _username = username;   
    delete _widget;
    qDebug()<< "close Login form";
    _widget = new MainWindow(this);
    qDebug()<< "MW created";
    _widget->show();

}

