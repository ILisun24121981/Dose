#ifndef EVENTFILTER_LOGIN_FORM_H
#define EVENTFILTER_LOGIN_FORM_H

#include <QObject>
#include "ui_login_form.h"

//Класс был создан для дополнения реакции на события связанные с ui
//благодаря такому подходу нет необходимости созавать наследников от
//стандартных элементов ui и переопределять их хендлеры событий
//можно просто перехватить событие нужного элемента
//и дополнить его (или изменить) в функции данного класса
// как-бы реализовав шаблон декоратора

class EventFilter_Login_Form: public QObject
{
     Q_OBJECT

    public:
        EventFilter_Login_Form(Ui::Login_form *ui);
    protected:
       bool eventFilter(QObject *watched, QEvent *event);
    private:
       Ui::Login_form *ui;
};

#endif // EVENTFILTER_LOGIN_FORM_H
