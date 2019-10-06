#include "controller.h"
#include "login_form.h"

Lis::Controller::Controller()
{
    _view = new Login_form(this);
}
Lis::Controller::~Controller(){

}
