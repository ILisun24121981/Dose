#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QDialog>
#include "login_processor.h"
#include "eventfilter_login_form.h"

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


    public slots:
        void on_buttonBox_Login_accepted();//connected to Login_form::login(QString userName,QString password)
        void indicate_fail_reason(Verification_result);//connected to Login_processor::verification_failed(Lis::Login_processor::Verification_result res)

    signals:
        void login(QString userName,QString password);//connected to Login_processor::verify_login(QString,QString)

    private:
        void connection();

        Ui::Login_form *ui;
        Login_processor *_LoginProcessor;
        EventFilter_Login_Form *_EvFilter;

        QString failure[3]={
            "Verification_problem",
            "Login_is_not_correct",
            "Password_is_not_correct",
        };

};
#endif // LOGIN_FORM_H
