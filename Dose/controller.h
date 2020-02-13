#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>
#include "logger.h"


namespace Lis {

    class Controller: public QObject
    {
        Q_OBJECT

        public:
            Controller();
            ~Controller();

        public:
            QWidget *_widget;
            QString _username;
            Logger *_logger;


        public slots:
            void LoginCompleted(QString username);//слот принимающий данные от Login_processor об результате Авторизации

    };

}// namespace Lis
#endif // CONTROLLER_H
