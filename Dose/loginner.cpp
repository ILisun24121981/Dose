#include "loginner.h"



Lis::Loginner::Loginner(Login_form *lF):QObject()
{
    _loginForm = lF;
}

Lis::Loginner::~Loginner()
{
    delete _loginForm;
}

void Lis::Loginner::loginCheck(QString username,QString password) {
    *(_loginForm->_mw) = new MainWindow();
}
