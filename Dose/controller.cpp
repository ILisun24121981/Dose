#include "controller.h"
#include "login_form.h"
#include <QObject>

Lis::Controller::Controller():QObject()
{
    _widget = new Login_form(this);
    _widget->show();

}

//void Lis::Controller::connectApp(){

//}

Lis::Controller::~Controller(){

}
