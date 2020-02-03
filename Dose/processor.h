#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <QObject>
#include "controller.h"


namespace Lis {
    class Processor:public QObject
    {

        Q_OBJECT

        public:
            Processor(Controller *ct, QObject *parent = nullptr);
            ~Processor();

//        public slots:
//            void connect();

//        signals:
//            void changeAppByController();

        public:
            Controller *_controller;
    };
} //namespace Lis
#endif // PROCESSOR_H
