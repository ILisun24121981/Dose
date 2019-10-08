#include "controller.h"
#include "login_form.h"

Lis::Controller::Controller()
{
    _widget = new Login_form(this);
    _widget->show();
}
Lis::Controller::~Controller(){

}
