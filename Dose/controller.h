#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>
#include "processor.h"

namespace Lis {

    class Controller: public QObject
    {
        Q_OBJECT

        public:
            Controller();
            ~Controller();

        public slots:
            void changeApp(QWidget *wd, Processor *pr);

        signals:
            void connectApp();

        public:
            QWidget *_widget;
            Processor *_processor;

    };

}// namespace Lis
#endif // CONTROLLER_H
