#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QObject>
#include "controller.h"


namespace Lis {
    class Processor:public QObject
    {

        public:
            Processor(Controller *ct);
            ~Processor();

        public:
            Controller *_controller;

    };
} //namespace Lis
#endif // PROCESSOR_H
