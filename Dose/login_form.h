#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QDialog>
#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login_form; };

QT_END_NAMESPACE

using namespace Lis;

class Login_form : public QDialog
{
    Q_OBJECT

    public:
        Login_form(Controller *ct = nullptr,QWidget *parent = nullptr);
        ~Login_form();

//    private slots:
//        void on_buttonBox_Login_accepted();

//    signals:
//        void login(QString userName,QString password);

    private:        
        Ui::Login_form *ui;
        Controller *_controller;

};
#endif // LOGIN_FORM_H
