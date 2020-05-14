#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>
#include "txt_logger.h"
#include "settings.h"


namespace Lis {

    class Controller: public QObject
    {
        Q_OBJECT

        public:
            Controller();
            ~Controller();

        public:
            bool AppState;

            QWidget *_widget;
            Txt_logger *_logger;
            Settings *_settings;

            QString _username;//временно

        public slots:          
            void autorisation_pass(QString username);//слот принимающий данные от Login_processor об результате Авторизации

    };

}// namespace Lis
#endif // CONTROLLER_H
