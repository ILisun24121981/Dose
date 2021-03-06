#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QDialog>
#include "login_processor.h"

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
        void connection();

    public slots:
        void on_buttonBox_Login_accepted();
        void indicate_fail_reason(Lis::Login_processor::Verification_result);

    signals:
        void login(QString userName,QString password);

    private:        
        Ui::Login_form *ui;
        Login_processor *_LoginProcessor;
        QString failure[4]={
            "Verification_Passed",
            "Passport_file_problem",
            "No_such_user",
            "Password_not_correct"
        };

};
#endif // LOGIN_FORM_H
