#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Login_form; }
QT_END_NAMESPACE

class Login_form : public QDialog
{
    Q_OBJECT

public:
    Login_form(QWidget *parent = nullptr);
    ~Login_form();

private:
    Ui::Login_form *ui;
};
#endif // LOGIN_FORM_H
