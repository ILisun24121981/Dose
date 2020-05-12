#include "eventfilter_login_form.h"
#include "QEvent"
#include "QMouseEvent"
#include "QDebug"
#include "QMetaObject"

EventFilter_Login_Form::EventFilter_Login_Form(Ui::Login_form *ui)
{
    this->ui =ui;
}

bool EventFilter_Login_Form::eventFilter(QObject *watched, QEvent *event){
//    qDebug()<<event->type();
//    qDebug()<<watched->metaObject()->className();
    if(event->type() == QEvent::MouseButtonPress){
        qDebug()<<"Pressed";
        QMouseEvent *me = static_cast<QMouseEvent *>(event);
        if(me->button() == Qt::MouseButton::LeftButton){
            qDebug()<<"LeftButtonPressed";
            if(watched == ui->lineEdit_UserName){
                ui->lineEdit_UserName->clear();
            }
            if(watched == ui->lineEdit_Password){
                ui->lineEdit_Password->clear();
            }
        }
    }

    //standart event processing
    return QObject::eventFilter(watched, event);
}

