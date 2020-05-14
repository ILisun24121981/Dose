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

            Controller *_controller;//инициализируется в конструкторе каждого процессора для доступа к внешним (для процессоров) слотам

    };
} //namespace Lis
#endif // PROCESSOR_H
