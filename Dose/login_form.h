#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QDialog>
#include "loginner.h"
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login_form; }
QT_END_NAMESPACE

using namespace Lis;

class Login_form : public QDialog
{
    Q_OBJECT

    public:
        Login_form(QWidget *parent = nullptr, MainWindow** mainw = nullptr );
        ~Login_form();

    private slots:
        void on_buttonBox_Login_accepted();

    signals:
        void login(QString userName,QString password);

    public:
        MainWindow** _mw;
    private:        
        Ui::Login_form *ui;
        Lis::Loginner *_loginner;
};
#endif // LOGIN_FORM_H
