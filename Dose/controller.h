#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>


namespace Lis {

    class Controller: public QObject
    {
        Q_OBJECT

        public:
            Controller();
            ~Controller();

        public:
            QWidget *_widget;
            QString usename;

        public slots:
            void LoginCompleted();//слот принимающий данные от Login_processor об результате Авторизации
    };

}// namespace Lis
#endif // CONTROLLER_H
